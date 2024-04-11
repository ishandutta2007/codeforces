#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'

const int INF = 1e18;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		int a[n]; for(int &i : a) cin >> i;
		sort(a, a+n);
		array<int, 2> best = {INF, -1};

		for(int i=0; i+1<n; ++i){
			best = min(best, {a[i+1] - a[i], i});
		}

		if(n == 2){
			cout << a[0] sp a[1] nl;
		}else{

			for(int i=0; i<n; ++i){
				cout << (a[(best[1]+1+i) % n]) << ' ';
			}
			cout nl;
			
		}
	}
}