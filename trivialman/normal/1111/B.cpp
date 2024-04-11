#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 100010;

LL n,k,m;
double a[N],s[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k>>m;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	s[0] = 0;
	rep(i,1,n)s[i]=s[i-1]+a[i];
	double ans=0;
	rep(i,0,n-1){
		if(i>m)break;
		ans = max(ans, (s[n] - s[i] + min(m-i,k*(n-i))) / (double)(n-i) );
		//cout<<i<<" "<<ans<<endl;
	}
	printf("%lf\n",ans);
	return 0;
}