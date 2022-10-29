#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
#define vs vector<string>
typedef long long LL;
const LL P = 998244353;
const int N = 2e5+5;
mt19937 rng(time(0));

int n, m, k, x, a[N];
LL sum, ans;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%d", &x);
		if(x>n-k) a[++m] = i;
	}
	sum = 1ll * (n+n-k+1) * k / 2;
	ans = 1;
	rep(i,2,m) ans = ans * (a[i]-a[i-1]) % P;
	cout<<sum<<" "<<ans<<endl;
	return 0;
}