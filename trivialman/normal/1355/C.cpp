#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
#define vs vector<string>
typedef long long LL;
const LL P = 998244353;
const int N = 50005;
mt19937 rng(time(0));

int T, n, a, b, c, d;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>a>>b>>c>>d;
	LL ans = 0;
	rep(z, c, d){
		int l = z - b + 1, r = z - a + 1;
		if(l>c) continue;
		if(r<=b){
			ans += 1ll * (b-a+1) * (c-b+1);
			continue;
		}
		
		ans += 1ll * (b-a+1) * (b-a+2) / 2;
		if (r>c) {
			//trapezoid 
			ans = ans - 1ll * (b-a+1) * (r-c) + 1ll * (r-c-1) * (r-c) / 2;
		}else{
			//rectangular
			ans = ans + 1ll * (b-a+1) * (c-r);
		}
		
		if(l<b){
			ans -= 1ll * (b-l) * (b-l+1) / 2;
		}
		//cout<<z<<" "<<ans<<endl;
	}
	
	cout<<ans<<endl;
	return 0;
}