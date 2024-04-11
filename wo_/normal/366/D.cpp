#include<cstdio>
#include<algorithm>

using namespace std;

struct UnionFind{
	int par[1010];
	void init(int N){
		for(int i=0;i<N;i++) par[i]=i;
	}
	int find(int x){
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y){
		x=find(x);y=find(y);
		if(x==y) return;
		par[x]=y;
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
};

UnionFind uf;

struct edge{
	int u,v;
	int l,r;
	edge(){}
	edge(int a,int b,int c,int d){
		u=a,v=b;
		l=c,r=d;
	}
};

bool cmp_l(const edge &e1,const edge &e2){
	return e1.l<e2.l;
}

bool cmp_r(const edge &e1,const edge &e2){
	return e1.r<e2.r;
}

edge es[3030];
edge tmp[3030];
int tln;

int ls[3030];
int ln;

int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b,l,r;
		scanf("%d%d%d%d",&a,&b,&l,&r);
		a--;b--;
		es[i]=edge(a,b,l,r);
		ls[i]=l;
	}
	sort(ls,ls+M);
	ln=unique(ls,ls+M)-ls;
	int ans=0;
	for(int i=0;i<ln;i++){
		int L=ls[i];
		//[L,*]
		tln=0;
		for(int j=0;j<M;j++){
			if(es[j].l<=L){
				tmp[tln++]=es[j];
			}
		}
		sort(tmp,tmp+tln,cmp_r);
		uf.init(N);
		int R=-1;
		for(int j=tln-1;j>=0;j--){
			int u=tmp[j].u,v=tmp[j].v;
			uf.unite(u,v);
			if(uf.same(0,N-1)){
				R=tmp[j].r;
				break;
			}
		}
		if(R==-1) continue;
		ans=max(ans,R-L+1);
	}
	if(ans==0){
		printf("Nice work, Dima!\n");
	}else{
		printf("%d\n",ans);
	}
	return 0;
}