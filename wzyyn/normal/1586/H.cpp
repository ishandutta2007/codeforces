#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N=200005;
int n,Q,val[N];

struct Tree2{
	
	vector<pair<int,int> > e[N];
	int fa[N][18];
	int fav[N][18];
	int dep[N];
	void add(int x,int y,int v){
		e[x].push_back(pair<int,int>(y,v));
		e[y].push_back(pair<int,int>(x,v));
	}
	void dfs(int x){
		for (auto i:e[x])
			if (i.first!=fa[x][0]){
				fa[i.first][0]=x;
				dep[i.first]=dep[x]+1;
				fav[i.first][0]=i.second;
				dfs(i.first);
			}
	}
	void build(){
		dfs(1);
		for (int i=1;i<=17;i++)
			for (int j=1;j<=n;j++){
				fa[j][i]=fa[fa[j][i-1]][i-1];
				fav[j][i]=max(fav[j][i-1],fav[fa[j][i-1]][i-1]);
			}
	}
	int ask(int x,int y){
		int v=0;
		if (dep[x]<dep[y]) swap(x,y);
		int del=dep[x]-dep[y];
		for (int i=17;i>=0;i--)
			if (del&(1<<i)){
				v=max(v,fav[x][i]);
				x=fa[x][i];
			}
		for (int i=17;i>=0;i--)
			 if (fa[x][i]!=fa[y][i]){
			 	v=max(v,max(fav[x][i],fav[y][i]));
			 	x=fa[x][i]; y=fa[y][i];
			 }
		if (x!=y){
			v=max(v,fav[x][0]);
			v=max(v,fav[y][0]);
		}
		return v;
	}
}T2;

struct edge{
	int x,y,v;
	bool operator <(const edge &a)const{
		return v>a.v;
	}
};
struct Tree1{
	int fa[N*2];
	int f[N*2][20];
	int val[N*2];
	int key1[N*2];
	int key2[N*2];
	int dep[N*2];
	int nd,tot;
	edge e[N];
	void add(int x,int y,int v){
		e[++tot]=(edge){x,y,v};
	}
	int get(int x){
		return x==fa[x]?x:fa[x]=get(fa[x]);
	}
	void build(){
		nd=n;
		for (int i=1;i<=n;i++){
			fa[i]=i,val[i]=::val[i];
			key1[i]=0,key2[i]=i; 
		}
		sort(e+1,e+tot+1);
		for (int i=1;i<=tot;i++){
			int x=get(e[i].x);
			int y=get(e[i].y);
			if (val[x]<val[y]) swap(x,y);
			fa[x]=fa[y]=++nd; f[x][0]=f[y][0]=nd;
			fa[nd]=nd; val[nd]=val[x]; dep[nd]=e[i].v;
			key1[nd]=0;
			if (val[x]>=val[y]) key1[nd]=max(key1[nd],key1[x]);
			if (val[y]>=val[x]) key1[nd]=max(key1[nd],key1[y]);
			if (val[x]==val[y]) key1[nd]=max(key1[nd],T2.ask(key2[x],key2[y]));
			key2[nd]=key2[x];
		}
		for (int i=1;i<=18;i++)
			for (int j=1;j<=nd;j++)
				f[j][i]=f[f[j][i-1]][i-1];
	}
	void ask(int x,int v){
		int y=x;
		for (int i=18;i>=0;i--)
			if (f[y][i]&&dep[f[y][i]]>=v)
				y=f[y][i];
		//cout<<y<<' '<<val[y]<<' '<<key1[y]<<' '<<key2[y]<<' '<<endl;
		printf("%d %d\n",val[y],max(key1[y],T2.ask(x,key2[y])));
	}
}T1;
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for (int i=1;i<n;i++){
		int x,y,a,b;
		scanf("%d%d%d%d",&x,&y,&a,&b);
		T1.add(x,y,a);
		T2.add(x,y,b);
	}
	T2.build();
	T1.build();
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		T1.ask(y,x);
	}
}