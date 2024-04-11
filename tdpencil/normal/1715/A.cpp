#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int t=1;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;

		int ans=2e9;
		if(a==1&&b==1){
			cout << 0 << "\n";
			continue;
		}
		ans=min(ans,(a-1)+(b-1)+min(a,b));
		cout << ans << '\n';
	}
}