#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'

void solve(){
	int k; cin >> k;
	string s; cin >> s;
	int a[k];
	for(int i=0; i<k; ++i) a[i] = s[i] - '0';

	for(int i=0; i<k; ++i){
		for(int j : {1, 4, 6, 8, 9}){
			if(a[i] == j){
				cout << 1 nl;
				cout << j nl;
				return;
			}
		}
	}
	for(int i=1; i<k; ++i){
		for(int j : {2, 5}){
			if(a[i] == j){
				cout << 2 nl;
				cout << a[0] << a[i];
				cout nl;
				return;
			}
		}
	}
	int cnt[11] = {};
	for(int i=0; i<k; ++i){
		++cnt[a[i]];
	}

	for(int j : {3, 7}){
		if(cnt[j] > 1){
			cout << 2 nl;
			cout << j << j nl;
			return;
		}
	}

	for(int m=1; m<1<<k; ++m){
		int num = 0;
		for(int i=0; i<k; ++i){
			if(m & (1<<i)) num = num * 10 + a[i];
		}
		for(int i=2; i<num; ++i){
			if(!(num % i)){
				cout << __builtin_popcount(m) nl;
				cout << num nl;
				return;
			}
		}
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) solve();	
}