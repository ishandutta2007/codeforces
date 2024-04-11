#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		int p[n]; for(int &i : p) cin >> i;
		string s; cin >> s;

		array<int, 2> b[n];

		for(int i=0; i<n; ++i)
			b[i] = {p[i], i};
		sort(b, b+n);
		reverse(b, b+n);

		int cnt = 0;

		for(char c : s) if(!(c - '0')) ++cnt;

		vector<int> hi(n-cnt), lo(cnt);
		iota(begin(lo), end(lo), 1);
		iota(begin(hi), end(hi), cnt + 1);

		for(int i=0; i<n; ++i){
			int j = b[i][1];
			if(s[j] - '0'){
				p[j] = hi.back();
				hi.pop_back();
			}else{
				p[j] = lo.back();
				lo.pop_back();

			}
		}

		for(int i : p) cout << i << ' ';
		cout << '\n';
	}
}