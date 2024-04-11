#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> G[100100];
int N;
vector<int> nums[100100];

vector<int> vecs[100100][20];

int par[100100][20];
int dep[100100];

void dfs(int v,int p,int d){
	par[v][0]=p;
	dep[v]=d;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(u==p) continue;
		dfs(u,v,d+1);
	}
}

void init_lca(){
	for(int j=1;j<20;j++){
		for(int i=0;i<N;i++){
			if(par[i][j-1]==-1) par[i][j]=-1;
			else par[i][j]=par[par[i][j-1]][j-1];
		}
	}
}

int get_lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int d=dep[u]-dep[v];
	for(int i=0;i<20;i++){
		if((d>>i)&1){
			u=par[u][i];
		}
	}
	if(u==v) return u;
	for(int i=19;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}

void merge_vec(vector<int> &v1,vector<int> &v2,vector<int> &res){
	int id1=0,id2=0;
	while(res.size()<10){
		if(id1==v1.size()&&id2==v2.size()) break;
		if(id1==v1.size()) res.push_back(v2[id2++]);
		else if(id2==v2.size()) res.push_back(v1[id1++]);
		else if(v1[id1]<v2[id2]) res.push_back(v1[id1++]);
		else res.push_back(v2[id2++]);
	}
}

void get_vecs(){
	for(int i=0;i<N;i++){
		vecs[i][0]=nums[i];
		sort(vecs[i][0].begin(),vecs[i][0].end());
	}
	for(int j=1;j<20;j++){
		for(int i=0;i<N;i++){
			int p=par[i][j-1];
			if(p==-1) vecs[i][j]=vecs[i][j-1];
			else merge_vec(vecs[i][j-1],vecs[p][j-1],vecs[i][j]);
		}
	}
}

vector<int> get_vec(int v,int p){
	vector<int> res;
	int d=dep[v]-dep[p];
	for(int i=0;i<20;i++){
		if((d>>i)&1){
			vector<int> nres;
			merge_vec(res,vecs[v][i],nres);
			swap(nres,res);
			v=par[v][i];
		}
	}
	return res;
}

vector<int> solve(int u,int v){
	int lca=get_lca(u,v);
	vector<int> vec_v,vec_u;
	vector<int> vec_lca;
	vec_v=get_vec(v,lca);
	vec_u=get_vec(u,lca);
	vec_lca=vecs[lca][0];
	vector<int> tmp,res;
	merge_vec(vec_u,vec_v,tmp);
	merge_vec(tmp,vec_lca,res);
	return res;
}

int main(){
	int M,Q;
	scanf("%d%d%d",&N,&M,&Q);
	for(int i=0;i<N-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1,0);
	for(int i=0;i<M;i++){
		int c;
		scanf("%d",&c);
		c--;
		nums[c].push_back(i+1);
	}
	init_lca();
	get_vecs();
	for(int q=0;q<Q;q++){
		int u,v,a;
		scanf("%d%d%d",&u,&v,&a);
		u--;v--;
		vector<int> ans=solve(u,v);
		if(ans.size()==0){
			printf("0\n");
			continue;
		}else{
			printf("%d ",min((int)ans.size(),a));
			for(int i=0;i<min((int)ans.size(),a);i++){
				printf("%d%c",ans[i],i+1==min((int)ans.size(),a)?'\n':' ');
			}
		}
	}
	return 0;
}