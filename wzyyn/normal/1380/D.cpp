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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=200005;
int n,m,x,k,y;
int a[N],b[N],p[N];
ll ans;
ll F(int l,int r){
	int len=0,mx=0;
	For(i,l,r) ++len,mx=max(mx,a[i]);
	int v=max(a[l-1],a[r+1]);
	if (len<k&&mx>v) puts("-1"),exit(0);
	ll ans=1ll*(len%k)*y+1ll*(len/k)*min(1ll*x,1ll*y*k);
	if (mx>v&&1ll*y*k<1ll*x) ans+=x-1ll*y*k;
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&x,&k,&y);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,m) scanf("%d",&b[i]);
	int pos=1;
	For(i,1,m){
		for (;pos<=n&&a[pos]!=b[i];++pos);
		if (pos>n) return puts("-1"),0;
		p[i]=pos++;
	}
	p[0]=0; p[m+1]=n+1;
	ll ans=0;
	For(i,1,m+1) ans+=F(p[i-1]+1,p[i]-1);
	cout<<ans<<endl;
}