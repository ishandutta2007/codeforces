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

void solve(){
	int a[22]; a[0]=0;
	ll n; int k;
	scanf("%lld%d",&n,&k);
	for (;n;a[++*a]=n%10,n/=10);
	a[(*a)+1]=0;
	int sum=0;
	For(i,1,*a) sum+=a[i];
	if (sum<=k) return puts("0"),void(0);
	For(i,1,*a){
		int dig=a[i+1]+1,sum=0;
		For(j,i+1,*a){
			sum+=dig%10;
			dig=dig/10+a[j+1];
		}
		sum+=dig;
		if (sum<=k){
			ll v1=1,v2=0;
			For(j,1,i) v1*=10;
			Rep(j,i,1) v2=v2*10+a[j];
			cout<<v1-v2<<endl;
			return;
		} 
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}