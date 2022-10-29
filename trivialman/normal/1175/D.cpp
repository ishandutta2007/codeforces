#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define CL(a,x) memset(a, x, sizeof(a))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 998244353;
const int N = 3e5+10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,k,a[N];
LL s[N];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",a+i);
	s[n+1] = 0;
	rrep(i,n,1) s[i] = s[i+1] + a[i];
	sort(s+2,s+n+1);
	reverse(s+2,s+n+1);
	LL ans = 0;
	rep(i,1,k) ans += s[i];
	printf("%lld\n",ans);
	return 0;
}