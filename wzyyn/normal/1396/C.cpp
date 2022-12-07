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
int n,r1,r2,r3,d,a[N];
ll f[N][10];
int main(){
	scanf("%d%d%d%d%d",&n,&r1,&r2,&r3,&d);
	For(i,1,n) scanf("%d",&a[i]);
	memset(f,60,sizeof(f));
	f[0][1]=0;
	For(i,1,n) For(s1,1,3) For(s2,1,3){
		if (s1==2&&s2!=2) continue;
		int Tin=(s1+1)/2+s2/2;
		int Tout=s1/2+(s2+1)/2;
		ll tmp=f[i-1][s1]+1ll*s2*d;
		ll val=1ll*a[i]*r1+r3;
		if (Tout>=1&&Tin>=2) val=min(val,min(1ll*r2,1ll*a[i]*r1+r1)+r1);
		f[i][s2]=min(f[i][s2],tmp+val);
	}
	ll ans=f[n][1]-d;
	ans=min(ans,f[n-1][2]+1ll*a[n]*r1+r3);
	cout<<ans<<endl;
}