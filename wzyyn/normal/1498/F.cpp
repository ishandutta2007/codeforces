#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=100005;
int n,k;
int a[N],fa[N];
int f[N][40],g[N][40];

vector<int> e[N];
void dfs1(int x){
	f[x][0]=a[x];
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dfs1(i);
			For(j,0,k-1) f[x][(j+1)%k]^=f[i][j];
		}
}
void dfs2(int x){
	for (auto i:e[x])
		if (i!=fa[x]){
			For(j,0,k-1) g[i][(j+1)%k]^=f[x][j]^g[x][j];
			For(j,0,k-1) g[i][(j+2)%k]^=f[i][j];
			dfs2(i);
		}
}
int main(){
	scanf("%d%d",&n,&k); k*=2;
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n)
		scanf("%d",&a[i]);
	dfs1(1);
	dfs2(1);
	for (int i=1;i<=n;i++){
		int s=0;
		for (int j=k/2;j<k;j++)
			s^=f[i][j]^g[i][j];
		printf(s?"1 ":"0 ");
	}
}