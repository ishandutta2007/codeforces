#include <bits/stdc++.h>
using namespace std;
#define int long long

const int D = 2050;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		int ans = 0;
		if(n % D){
			cout << -1 << '\n';
		}else{
			for(int div=1e18; div; div/=10LL){
				while(n >= (div*D)){
					n -= div*D;
					++ans;
				}
			}
			cout << ans << '\n';
		}
	}
}