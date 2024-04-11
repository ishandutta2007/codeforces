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
const int N=1000005;
int n;
ll k;
ll a[N],b[N],c[N],ans;
int main(){
	scanf("%d%lld",&n,&k);
	For(i,1,n) scanf("%lld",&a[i]),a[i+n]=a[i];
	For(i,1,2*n) b[i]=b[i-1]+1ll*a[i]*(a[i]+1)/2;
	For(i,1,2*n) c[i]=c[i-1]+a[i];
	int p=0;
	For(i,n+1,2*n){
		for (;c[i]-c[p]>k;++p);
		//cout<<i<<' '<<p<<endl;
		ll v=b[i]-b[p];
		int rem=k-(c[i]-c[p]);
		v+=1ll*rem*(2*a[p]-rem+1)/2;
		//cout<<i<<' '<<p<<' '<<rem<<' '<<v<<' '<<b[i]-b[p]<<endl;
		ans=max(ans,v);
	}
	printf("%lld\n",ans);
}