#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

struct Edge{
	int to,cost;
	Edge(){}
	Edge(int a,int b):to(a),cost(b){}
};

vector<Edge> G[100100];
int N;

int S,T;

int prv_zeropath[100100];
int dis_zeroonly[100100];

int dis_unweighted[100100];//to S

vector<int> prv_anspath[100100];

void bfs_unweighted(int s){
	int *res=dis_unweighted;
	for(int i=0;i<N;i++) res[i]=-1;
	res[s]=0;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++){
			int u=G[v][i].to;
			if(res[u]!=-1&&res[u]<=res[v]+1) continue;
			res[u]=res[v]+1;
			que.push(u);
		}
	}
}

void bfs_zeroonly(int s){
	int *res=dis_zeroonly;
	int *prv=prv_zeropath;
	for(int i=0;i<N;i++){
		res[i]=-1;
		prv[i]=-1;
	}
	res[s]=0;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++){
			if(G[v][i].cost!=0) continue;
			int u=G[v][i].to;
			if(res[u]!=-1&&res[u]<=res[v]+1) continue;
			prv[u]=v;
			res[u]=res[v]+1;
			que.push(u);
		}
	}
}

int prv_path_restore[100100];
int dis_path_restore[100100];
vector<int> path_restore(int s,int t,string cost){
	if(s==t){
		vector<int> res;
		res.push_back(s);
		return res;
	}
	int *prv=prv_path_restore;
	int *dis=dis_path_restore;
	for(int i=0;i<N;i++) prv[i]=-1;
	for(int i=0;i<N;i++) dis[i]=-1;
	queue<int> que;
	que.push(s);
	dis[s]=0;
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(int i=0;i<G[v].size();i++){
			int u=G[v][i].to;
			if(dis[u]!=-1&&dis[u]<=dis[v]+1) continue;
			if(G[v][i].cost!=(int)(cost[dis[v]]-'0')) continue;
			prv[u]=v;
			dis[u]=dis[v]+1;
			que.push(u);
			if(u==t) goto endwhile;
		}
	}
	endwhile:;
	vector<int> res;
	int cur=t;
	while(cur!=s){
		res.push_back(cur);
		cur=prv[cur];
	}
	res.push_back(s);
	return res;
}

void solve(){
	bfs_unweighted(S);
	bfs_zeroonly(T);
	
//	printf("a\n");
	string cost="";
	vector<int> cur_vlist;
	
	int L=100100;
	for(int i=0;i<N;i++){
		if(dis_zeroonly[i]==-1) continue;
		if(L<dis_unweighted[i]) continue;
		if(L>dis_unweighted[i]) cur_vlist.clear();
		L=dis_unweighted[i];
		cur_vlist.push_back(i);
	}
	
	for(int i=0;i<N;i++){
		prv_anspath[i].clear();
	}
	
	for(int l=L;l>=1;l--){
		vector<int> new_vlist;
		int nxt_cost=10;
		for(int i=0;i<cur_vlist.size();i++){
			int v=cur_vlist[i];
			for(int j=0;j<G[v].size();j++){
				int u=G[v][j].to;
				if(dis_unweighted[u]!=l-1) continue;
				nxt_cost=min(nxt_cost,G[v][j].cost);
			}
		}
		
		for(int i=0;i<cur_vlist.size();i++){
			int v=cur_vlist[i];
			for(int j=0;j<G[v].size();j++){
				int u=G[v][j].to;
				if(dis_unweighted[u]!=l-1) continue;
				if(G[v][j].cost!=nxt_cost) continue;
				prv_anspath[u].push_back(v);
				new_vlist.push_back(u);
			}
		}
		
		cost+=(char)('0'+nxt_cost);
		cur_vlist=new_vlist;
	}
	
//	printf("b\n");
//	printf("%s\n",cost.c_str());
//	return;
	vector<int> valid_vlist;
	valid_vlist.push_back(S);
	for(int l=0;l<L;l++){
		vector<int> new_valid_vlist;
		for(int i=0;i<valid_vlist.size();i++){
			int v=valid_vlist[i];
			for(int j=0;j<prv_anspath[v].size();j++){
				int u=prv_anspath[v][j];
				new_valid_vlist.push_back(u);
			}
		}
		sort(new_valid_vlist.begin(),new_valid_vlist.end());
		new_valid_vlist.erase(unique(new_valid_vlist.begin(),new_valid_vlist.end()),new_valid_vlist.end());
		valid_vlist=new_valid_vlist;
	}
	
//	printf("c\n");
	int start_nonzero;
	int num_leading_zero=100100;
	for(int i=0;i<valid_vlist.size();i++){
		int v=valid_vlist[i];
		if(num_leading_zero>dis_zeroonly[v]){
			num_leading_zero=dis_zeroonly[v];
			start_nonzero=v;
		}
	}
	
//	printf("d\n");
//	printf("%d\n",start_nonzero);
	vector<int> zero_path,nonzero_path;
	nonzero_path=path_restore(start_nonzero,S,cost);
	string zero_cost;
	for(int i=0;i<dis_zeroonly[start_nonzero];i++) zero_cost+='0';
	zero_path=path_restore(T,start_nonzero,zero_cost);
	
	vector<int> ans_path;
	for(int i=0;i<(int)nonzero_path.size()-1;i++) ans_path.push_back(nonzero_path[i]);
	for(int i=0;i<zero_path.size();i++) ans_path.push_back(zero_path[i]);
	
	if(cost=="") cost="0";
	printf("%s\n",cost.c_str());
	printf("%d\n",ans_path.size());
	for(int i=0;i<ans_path.size();i++){
		printf("%d%c",ans_path[i],i+1==ans_path.size()?'\n':' ');
	}
}

void input(){
	int M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		G[u].push_back(Edge(v,c));
		G[v].push_back(Edge(u,c));
	}
	S=0;
	T=N-1;
}

int main(){
	input();
	solve();
	return 0;
}