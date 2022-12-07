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
const int N=200005;
int n,S,c[N];
int f[N],g[N],fa[N];
vector<int> e[N];
/*
f[x]=c[i]+max(f[i],0) 
*/
void DP1(int x){
	f[x]=c[x];
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			DP1(i);
			f[x]+=max(0,f[i]);
		}
}
void DP2(int x){
	for (auto i:e[x])
		if (i!=fa[x]){
			g[i]=max(f[x]-max(0,f[i])+g[x],0);
			DP2(i);
		}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&c[i]);
	For(i,1,n) c[i]=(c[i]?1:-1);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	DP1(1);
	DP2(1);
	For(i,1,n) printf("%d ",f[i]+g[i]);
}