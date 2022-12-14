#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct UnionFind{
	int N;
	int par[330];
	void init(int N_){
		for(int i=0;i<N_;i++) par[i]=i;
	}
	int find(int x){
		if(x==par[x]) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y) return;
		par[x]=y;
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
};

UnionFind uf;

char ch[330];

int p[330];
vector<int> tmp[330];
vector<int> tmp2[330];

int ans[330];

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",p+i);
	uf.init(N);
	for(int i=0;i<N;i++){
		scanf("%s",ch);
		for(int j=0;j<N;j++){
			if(ch[j]=='1'){
				uf.unite(i,j);
			}
		}
	}
	for(int i=0;i<N;i++){
		tmp[uf.find(i)].push_back(i);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<tmp[i].size();j++) tmp2[i].push_back(p[tmp[i][j]]);
	}
	for(int i=0;i<N;i++) sort(tmp2[i].begin(),tmp2[i].end());
	for(int i=0;i<N;i++){
		for(int j=0;j<tmp[i].size();j++){
			ans[tmp[i][j]]=tmp2[i][j];
		}
	}
	for(int i=0;i<N;i++) printf("%d%c",ans[i],i==N-1?'\n':' ');
	return 0;
}