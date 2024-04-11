/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y10101010101
#define y0			y01010101010
#define int long long
typedef pair<int,int> pii;
typedef long long ll;
const ll MOD=998244353;
inline ll qpow(int x,int e){
	ll ans=1;while(e){
		if(e&1) ans=ans*x%MOD;
		x=x*x%MOD;e>>=1;
	} return ans;
}
int n,a[300005];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	int sum=0;
	for(int i=1;i<=n;i++) sum-=a[i];
	for(int i=n+1;i<=2*n;i++) sum+=a[i];
	sum%=MOD;
	int c=1;
	for(int i=1;i<=2*n;i++) c=c*i%MOD;
	for(int i=1;i<=n;i++) c=c*qpow(i,MOD-2)%MOD;
	for(int i=1;i<=n;i++) c=c*qpow(i,MOD-2)%MOD;
	cout<<sum*c%MOD<<endl;
	return 0;
}