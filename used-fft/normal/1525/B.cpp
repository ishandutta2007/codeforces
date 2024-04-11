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
		int a[n]; for(int &i : a) cin >> i;
		bool ok = true;
		for(int i=0; i<n; ++i) if(a[i] != i+1) ok = false;
		if(!ok){
			if(a[0] == 1 || a[n-1] == n) cout << 1 nl;
			else{
				if(a[0] == n && a[n-1] == 1) cout << 3 nl;
				else cout << 2 nl;
			}
		}else cout << 0 nl;
	}
}