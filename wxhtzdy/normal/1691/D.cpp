#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 1e9 + 7;
const int MAXN = 200050;
const int MAXL = 20;

struct sparse1{
	lint st[MAXN][MAXL];
	int logs[MAXN];
	void init(int n, vector<lint> a) {
		for(int i = 0; i <= n; i++) st[i][0] = a[i];
		for(int j = 1; j < MAXL; j++)
			for(int i = 0; i + (1 << j) <= n+1; i++)
				st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		for(int i = 2; i <= n+2; i++) logs[i] = logs[i >> 1] + 1;
	}
	lint get(int l, int r){
		int k = logs[r - l + 1];
		return min(st[l][k], st[r - (1 << k) + 1][k]);
	}
} mn;

struct sparse2{
	lint st[MAXN][MAXL];
	int logs[MAXN];
	void init(int n, vector<lint> a) {
		for(int i = 0; i <= n; i++) st[i][0] = a[i];
		for(int j = 1; j < MAXL; j++)
			for(int i = 0; i + (1 << j) <= n+1; i++)
				st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		for(int i = 2; i <= n+2; i++) logs[i] = logs[i >> 1] + 1;
	}
	lint get(int l, int r){
		int k = logs[r - l + 1];
		return max(st[l][k], st[r - (1 << k) + 1][k]);
	}
} mx;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i++) cin >> a[i];
		vector<lint> sum(n + 1);
		for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
		mn.init(n, sum); mx.init(n, sum);
		vector<int> l(n + 1), r(n + 1);
		vector<int> stk;
		for(int i = 1; i <= n; i++) {
			while(sz(stk) > 0 && a[stk.back()] < a[i]) stk.pop_back();
			if(sz(stk) == 0) l[i] = 0;
			else l[i] = stk.back();
			stk.push_back(i);
		}
		stk.clear();
		for(int i = n; i >= 1; i--) {
			while(sz(stk) > 0 && a[stk.back()] <= a[i]) stk.pop_back();
			if(sz(stk) == 0) r[i] = n + 1;
			else r[i] = stk.back();
			stk.push_back(i);
		}
		bool ok = true;
		for(int i = 1; i <= n; i++) {
			if(mx.get(i, r[i] - 1) - mn.get(l[i], i - 1) > a[i]){
				ok = false;
			}
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
}