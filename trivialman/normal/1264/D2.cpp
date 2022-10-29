#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define CL(a,x) memset(a, x, sizeof(a))
#define ar2 array<int, 2>
typedef long long LL;
const int P = 998244353;
const int N = 1e6+5;
const double PI = acos(-1);
mt19937 rng(time(0));

char a[N];
int n, m, l, r, l1, ans, s0[N], s1[N];
LL fac[N], ifac[N];

LL pw(LL x,int n){
	LL res=1;
	for(;n;n>>=1,x=x*x%P)if(n&1)res=res*x%P;
	return res;
}
LL C(int a,int b){return fac[a]*ifac[b]%P*ifac[a-b]%P;}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%s",a+1);
	n = strlen(a+1);
	rep(i,1,n) m+=(a[i]=='?'), r+=(a[i]==')');
	
	fac[0] = 1;
	rep(i,1,m) fac[i] = fac[i-1] * i % P;
	ifac[m] = pw(fac[m], P-2);
	rrep(i,m-1,0) ifac[i] = ifac[i+1] * (i+1) % P;
	
	s0[0] = s1[0] = 1;
	rep(i,1,m) s0[i]=(s0[i-1]+C(m,i))%P;	
	rep(i,1,m-1) s1[i]=(s1[i-1]+C(m-1,i))%P;
	
	rep(i,1,n){
		l+=(a[i-1]=='(');
		l1+=(a[i-1]=='?');
		r-=(a[i]==')');
		bool f=a[i]=='?';
		int x = r+m-f-l1-l-1;
		x = min(x,m-f);
		ans = (ans + (a[i]!=')'&&x>=0 ? (f?s1:s0)[x] : 0) ) % P;
	}
	cout<<ans<<endl;
	return 0;
}