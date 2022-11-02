#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'

#define a(x) (s[x]-'0')

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	s = '$' + s;

	int req = n / 2;

	for(int i=req+1; i<=n; ++i){
		if(!a(i)){
			cout << 1 sp i sp 1 sp i - 1 nl;
			return;
		}
	}

	if(a(req)){
		cout << req sp n - 1 sp req + 1 sp n nl;
	}else{
		cout << req sp n - 0 sp req + 1 sp n nl;
	}

}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--) solve();	
}