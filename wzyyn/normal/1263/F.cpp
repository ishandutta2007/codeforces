#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=2005;
vector<int> e1[N],e2[N];
vector<int> vec1[N],vec2[N];
int id1[N],st1[N],ed1[N];
int id2[N],st2[N],ed2[N];
int n,m,x,f1[N][N],f2[N][N],g[N];
void dfs1(int x){
	if (id1[x]) st1[x]=ed1[x]=id1[x];
	else st1[x]=n+1,ed1[x]=0;
	for (auto i:e1[x]){
		dfs1(i);
		st1[x]=min(st1[x],st1[i]);
		ed1[x]=max(ed1[x],ed1[i]);
	}
	if (x!=1)
		vec1[ed1[x]].PB(st1[x]);
}
void dfs2(int x){
	if (id2[x]) st2[x]=ed2[x]=id2[x];
	else st2[x]=n+1,ed2[x]=0;
	for (auto i:e2[x]){
		dfs2(i);
		st2[x]=min(st2[x],st2[i]);
		ed2[x]=max(ed2[x],ed2[i]);
	}
	if (x!=1)
		vec2[ed2[x]].PB(st2[x]);
}
void init_dp(){
	For(i,1,n) For(j,i,n){
		f1[i][j]=f1[i][j-1];
		f2[i][j]=f2[i][j-1];
		for (auto k:vec1[j]) f1[i][j]+=(k>=i);
		for (auto k:vec2[j]) f2[i][j]+=(k>=i); 
		//printf("%d %d %d %d\n",i,j,f1[i][j],f2[i][j]); 
	}
}
void dp(){
	For(i,0,n) For(j,0,i-1)
		g[i]=max(g[i],g[j]+max(f1[j+1][i],f2[j+1][i]));
	printf("%d\n",g[n]);
}
int main(){
	scanf("%d",&n);
	scanf("%d",&m);
	For(i,2,m){
		scanf("%d",&x);
		e1[x].PB(i);
	}
	For(i,1,n){
		scanf("%d",&x);
		id1[x]=i;
	}
	scanf("%d",&m);
	For(i,2,m){
		scanf("%d",&x);
		e2[x].PB(i);
	}
	For(i,1,n){
		scanf("%d",&x);
		id2[x]=i;
	}
	dfs1(1);
	dfs2(1);
	init_dp();
	dp();
}