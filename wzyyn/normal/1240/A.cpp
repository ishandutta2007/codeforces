#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 fdhjksa
using namespace std;
const int N=200005;
ll a[N],lim;
int n,p1,r1,p2,r2;
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	For(i,1,n) a[i]=a[i-1]+a[i]/100;
	scanf("%d%d%d%d",&p1,&r1,&p2,&r2);
	if (p1<p2) swap(p1,p2),swap(r1,r2);
	int S1=0,S2=0,S3=0;
	scanf("%lld",&lim);
	For(i,1,n){
		if (i%r1==0&&i%r2==0) ++S1;
		else if (i%r1==0) ++S2;
		else if (i%r2==0) ++S3;
		ll S=(a[n]-a[n-S1])*(p1+p2);
		S+=(a[n-S1]-a[n-S1-S2])*p1;
		S+=(a[n-S1-S2]-a[n-S1-S2-S3])*p2;
		if (S>=lim){
			printf("%d\n",i);
			return;
		}
	}
	puts("-1");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}