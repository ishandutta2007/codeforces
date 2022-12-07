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
const int N=505;
int n,m,g[N*2];
int f[N][N*2];
struct node{
	int l,r,w,s,v;
}a[N];
bool cmp(node a,node b){
	return a.r==b.r?a.l>b.l:a.r<b.r;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d%d%d%d%d",&a[i].l,&a[i].r,&a[i].w,&a[i].s,&a[i].v);
	sort(a+1,a+n+1,cmp);
	a[n+1].l=0; a[n+1].r=n*2; a[n+1].s=m;
	For(i,1,n+1) For(j,a[i].w,m){
		int p=a[i].l; g[p]=0;
		For(k,1,i-1) if (a[k].l>=a[i].l){
			for (;p<a[k].r;) p++,g[p]=g[p-1];
			g[p]=max(g[p],g[a[k].l]+f[k][min(j-a[i].w,a[i].s)]);
		}
		f[i][j]=g[p]+a[i].v;
	}
	printf("%d ",f[n+1][m]);
	
}