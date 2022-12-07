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
const int N=4005;
struct node{
	int v,c,t;
}a[N];
bool cmp(node a,node b){
	return a.t<b.t;
}
int n,p;
int f[N][N],g[N][N];
int Be(int x){
	return (x-1)/p;
}
int main(){
	scanf("%d%d",&n,&p);
	For(i,1,n) scanf("%d%d%d",&a[i].v,&a[i].c,&a[i].t);
	sort(a+1,a+n+1,cmp);
	for (int i=1,l=1,r=1;i<=a[n].t;i+=p){
		for (;l<=n&&a[l].t<i;++l);
		for (;r<=n&&a[r].t<i+p;++r);
		if (l>(--r)) continue;
		for (int j=l,la=0;j<=r;la=j++){
			memcpy(f[j],f[la],sizeof(f[j]));
			Rep(k,N-1,a[j].v) f[j][k]=max(f[j][k],f[j][k-a[j].v]+a[j].c);
		}
		for (int j=r,la=0;j>=l;la=j--){
			memcpy(g[j],g[la],sizeof(g[j]));
			Rep(k,N-1,a[j].v) g[j][k]=max(g[j][k],g[j][k-a[j].v]+a[j].c);
		}
	}
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x,y,ans=0;
		scanf("%d%d",&x,&y);
		int l=lower_bound(a+1,a+n+1,(node){0,0,x-p+1},cmp)-a;
		int r=upper_bound(a+1,a+n+1,(node){0,0,x},cmp)-a-1;
		if (l<=r){
			if (Be(a[l].t)==Be(a[r].t))
				ans=(Be(a[l].t)==Be(x)?f[r][y]:g[l][y]);
			else{
				For(i,0,y)
					ans=max(ans,g[l][i]+f[r][y-i]);
			}
		}
		printf("%d\n",ans);
	}
}