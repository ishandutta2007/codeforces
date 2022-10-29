#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 300010;

int n;
LL p,k,a[N];

LL calc(LL x){
	return (x*x%p*x%p*x%p-(k*x%p)+p)%p;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin>>n>>p>>k;
	rep(i,1,n)cin>>a[i],a[i]=calc(a[i]%p);
	map<LL, LL> cnt;
	rep(i,1,n)cnt[a[i]]++;
	LL ans = 0;
	for(auto &x : cnt){
		ans += x.second*(x.second-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}