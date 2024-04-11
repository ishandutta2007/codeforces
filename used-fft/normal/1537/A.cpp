#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		int a[n], sum = 0;
		for(int &i : a) cin >> i, sum += i;
		if(sum >= n){
			cout << sum-n nl;
		}else{
			cout << 1 nl;
		}
	}
}