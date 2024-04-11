#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 100010;

LL n, a[N], b[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,1,n)cin>>a[i]>>b[i];
	LL ans = 0;
	rep(i,1,n)ans+=a[i];
	ans=ans*(n-1);
	rep(i,1,n)b[i]-=a[i];
	sort(b+1,b+n+1);
	rep(i,1,n)ans+=b[i]*(n-i);
	cout<<ans<<endl;
	return 0;
}