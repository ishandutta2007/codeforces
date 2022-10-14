#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;
const int MAXN = 100050;

vector<int> gph[MAXN];
bool was[MAXN], spec[MAXN], ok[MAXN], f;

void dfs(int x){
	if(spec[x]) f = false;
	was[x] = true;
	for(auto &y : gph[x]){
		if(!was[y]) dfs(y);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		vector<int> a(n);
		for(int &i : a) cin >> i, i--;
		vector<int> b(n);
		for(int &i : b) cin >> i, i--;
		vector<int> d(n);
		for(int &i : d) cin >> i;
		for(int i = 0; i < n; i++){
			gph[i].clear();
			was[i] = false;
			spec[i] = false;
			ok[i] = true;
		}
		for(int i = 0; i < n; i++){
			gph[a[i]].push_back(b[i]);
			gph[b[i]].push_back(a[i]);
			if(d[i] != 0){
				spec[a[i]] = true;
				spec[b[i]] = true;
			}
			if(a[i] == b[i]) ok[a[i]] = false;
		}
		int ans = 1;
		for(int i = 0; i < n; i++){
			if(!was[i] && ok[i]){
				f = true;
				dfs(i);
				if(f) ans = (ans * 2) % mod;
			}
		}
		cout << ans << "\n";
	}
}