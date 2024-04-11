#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int i = a; i <= (n); ++i)
#define repD(i, a, n) for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin >> t;
	while(t--){
		int k; cin >> k;
		int a[7]; rep(i,7) cin >> a[i];
		int w = 0;
		rep(i,7) if(a[i] == 1) w++;
		int p[7],s[7];
		p[0] = a[0];
		s[6] = a[6];
		for(int i = 1; i < 7; i++) p[i] = a[i] + p[i-1];
		for(int i = 5; i >= 0; i--) s[i] = a[i] + s[i+1];
		int ans = INT_MAX;
		rep(i,7){
			rep(j,7){
				int k_ = k;
				k_ -= p[i];
				k_ -= s[j];
				if(k_ < 0){
					continue;
				}else if(k_%w == 0){
					ans = min(ans, 8 + i - j + (k_/w)*7);
				}
			}
		}
		rep(i,7){
			int c = 0;
			repA(j,i,6){
				if(a[j]) c++;
				if(c == k) ans = min(ans, j-i+1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}