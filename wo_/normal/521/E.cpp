#include<cstdio>
#include<vector>
#include<utility>
#include<map>
#include<cassert>
#include<algorithm>

using namespace std;

vector<int> G[200200];

int pre[200200],low[200200];
int par[200200];
int pos[200200];

int c=1;
void dfs(int v,int p){
	par[v]=p;
	pre[v]=c++;
	low[v]=pre[v];
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(u==p) continue;
		if(pre[u]!=0){
			low[v]=min(low[v],pre[u]);
		}else{
			dfs(u,v);
			low[v]=min(low[v],low[u]);
		}
	}
	pos[v]=c;
}

struct P:pair<int,int>{
	P(int a,int b){
		this->first=min(a,b);
		this->second=max(a,b);
	}
};

map<P,int> ids;
vector<P> edges[200200];

int d=0;
int cur_ch[200200];
void get_compo(int v,int p){
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(u==p) continue;
		if(pre[u]<pre[v]){
			int ch=cur_ch[u];
			ids[P(u,v)]=ids[P(u,ch)];
			continue;
		}
		if(par[u]!=v) continue;
		cur_ch[v]=u;
		if(p==-1 || low[u]>=pre[v]){
			ids[P(u,v)]=d++;
		}else{
			ids[P(u,v)]=ids[P(p,v)];
		}
		get_compo(u,v);
	}
}

void get_compo2(){
	map<P,int>::iterator it=ids.begin();
	for(;it!=ids.end();it++){
		P p=it->first;
		int id=it->second;
		edges[id].push_back(p);
	}
}

vector<int> G2[200200];

bool used[200200];
bool in_cycle[200200];

vector<int> vs;

int prev[200200];
vector<int> cycle;

int nearest_cycle_v[200200];

vector<P> backs;

void get_graph(int id){
	vs.clear();
	backs.clear();
	for(int i=0;i<edges[id].size();i++){
		P p=edges[id][i];
		vs.push_back(p.first);
		vs.push_back(p.second);
	}
	sort(vs.begin(),vs.end());
	vs.erase(unique(vs.begin(),vs.end()),vs.end());
	for(int i=0;i<vs.size();i++){
		G2[vs[i]].clear();
		used[vs[i]]=false;
		nearest_cycle_v[vs[i]]=-1;
		in_cycle[vs[i]]=false;
	}
	for(int i=0;i<edges[id].size();i++){
		P p=edges[id][i];
		int u=p.first,v=p.second;
		G2[u].push_back(v);
		G2[v].push_back(u);
		if(par[u]!=v&&par[v]!=u){
			backs.push_back(P(u,v));
		}
	}
}

int get_nearest_cycle_v(int v){
	if(nearest_cycle_v[v]!=-1) return nearest_cycle_v[v];
	if(in_cycle[v]){
		nearest_cycle_v[v]=v;
		return v;
	}
	int &res=nearest_cycle_v[v];
	int t=cycle.back();
//	if(pre[v]<pre[t]){
	if(!(pre[t]<=pre[v]&&pre[v]<=pos[t])){
		return res=t;
	}
	res=get_nearest_cycle_v(par[v]);
	return res;
}

vector<int> get_tree_path(int v,int a){
	if(v==a){
		vector<int> res;
		res.push_back(v);
		return res;
	}
	bool flipped=false;
	if(pre[v]<pre[a]){
		swap(v,a);
		flipped=true;
	}
	vector<int> res;
	int cur=v;
	while(true){
		res.push_back(cur);
		if(cur==a) break;
		cur=par[cur];
	}
	if(flipped){
		reverse(res.begin(),res.end());
	}
	return res;
}

void app(vector<int> &res,vector<int> a){
	assert(res.back()==a.front());
	for(int i=1;i<a.size();i++){
		res.push_back(a[i]);
	}
}

void print(vector<int> vec){
	printf("%d",vec.size());
	for(int i=0;i<vec.size();i++){
		printf(" %d",vec[i]+1);
	}
	printf("\n");
}

void solve(int id){
	get_graph(id);
	if(backs.size()<=1) return;
	P back=backs[0];
	int u=back.first,v=back.second;
	if(pre[u]<pre[v]) swap(u,v);
	cycle.clear();
	int cur=u;
	while(cur!=v){
		cycle.push_back(cur);
		cur=par[cur];
	}
	cycle.push_back(v);
	for(int i=0;i<cycle.size();i++){
		int v=cycle[i];
		in_cycle[v]=true;
	}
	for(int i=0;i<vs.size();i++){
		int v=vs[i];
		get_nearest_cycle_v(v);
	}
	for(int i=1;i<backs.size();i++){
		P cur_back=backs[i];
		int x=cur_back.first,y=cur_back.second;
		if(pre[x]<pre[y]) swap(x,y);
		if(nearest_cycle_v[x]==nearest_cycle_v[y]){
			continue;
		}
		int s=nearest_cycle_v[x],t=nearest_cycle_v[y];
		vector<int> p1,p2,p3;
		p1=get_tree_path(s,x);
		p1.push_back(y);
		vector<int> tmp=get_tree_path(y,t);
		app(p1,tmp);
		
		p2=get_tree_path(s,t);
		
		p3=get_tree_path(s,u);
		p3.push_back(v);
		tmp=get_tree_path(v,t);
		app(p3,tmp);
		
		printf("YES\n");
		print(p1);
		print(p2);
		print(p3);
		exit(0);
	}
}

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<N;i++){
		if(pre[i]==0) dfs(i,-1);
	}
	for(int i=0;i<N;i++){
		if(par[i]==-1) get_compo(i,-1);
	}
	get_compo2();
	for(int i=0;i<d;i++){
		solve(i);
	}
	printf("NO\n");
	return 0;
}


/*
int find_cycle(int v,int p){
	used[v]=true;
	for(int i=0;i<G2[v].size();i++){
		int u=G2[v][i];
		if(u==p) continue;
		prev[u]=v;
		if(used[u]){
			return u;
		}
		int ret=find_cycle(u,v);
		if(ret>=0) return ret;
	}
	return -1;
}
void get_cycle(){
	int u=find_cycle(vs[0],-1);
	cycle.push_back(u);
	int cur=prev[u];
	while(cur!=u){
		cycle.push_back(cur);
		cur=prev[cur];
	}
}*/