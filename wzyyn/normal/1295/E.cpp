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
int n,p[N],a[N];
ll t[N*4],tg[N*4],ans=1ll<<60;
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tg[k]+=v,t[k]+=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	t[k]=min(t[k*2],t[k*2+1])+tg[k];
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&p[i]);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) change(1,0,n,p[i],n,a[i]);
	For(i,1,n-1){
		change(1,0,n,p[i],n,-a[i]);
		change(1,0,n,0,p[i]-1,a[i]);
		ans=min(ans,t[1]);
	}
	printf("%lld\n",ans);
}