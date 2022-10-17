#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int N = 5010;
const int MOD = 1e9 + 7;
short c[N][N], a[N], arr[N][N];
bool have[N][N];
void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return (a * 1ll * b) % MOD;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
  	cin >> a[i];
  }	
  for (int i = 1; i <= n; i++) {
  	for (int j = 1; j <= n; j++) {
  		c[i][j] = c[i - 1][j];
  	}
  	c[i][a[i]]++;
  }
  for (int i = 1; i <= m; i++) {
  	int type, cnt;
  	cin >> type >> cnt;
  	arr[type][cnt]++;
  	have[type][cnt] = true;
  }	
  for (int i = 1; i <= n; i++) {
  	for (int j = 1; j <= n; j++) {
  		arr[i][j] += arr[i][j - 1];
  	}
  }
  pair<int, int> mx = {0, 0};
  for (int pref = 0; pref <= n; pref++) {
  	pair<int, int> cur = {0, 1};
  	if (pref > 0) {
  		int vl = a[pref];
  		int ca = c[pref][vl], cb = c[n][vl] - ca;
  		if (!have[vl][ca]) {
  			continue;
  		}
  		cur.F++;
  		if (cb >= ca) {
  			if (arr[vl][cb] > 1) {
  				cur.F++;
  				cur.S = mult(cur.S, arr[vl][cb] - 1);
  			}
  		}
  		else {
  			if (arr[vl][cb] > 0) {
  				cur.F++;
  				cur.S = mult(cur.S, arr[vl][cb]);
  			}
  		}
  		//cout << pref << ' ' << cur.F << ' ' << cur.S << '\n';
  	}
  	for (int i = 1; i <= n; i++) {
  		if (a[pref] == i) {
  			continue;
  		}
  		int a = c[pref][i], b = c[n][i] - a;
  		if (a > b) {
  			swap(a, b);
  		}
  		if (arr[i][a] >= 1 && arr[i][b] >= 2) {
  			cur.F += 2;
  			cur.S = mult(cur.S, mult(arr[i][a], arr[i][b] - 1));
  		}
  		else if (arr[i][b] > 0) {
  			cur.F++;
  			cur.S = mult(cur.S, arr[i][a] + arr[i][b]);
  		}
  	}
  	if (cur.F > mx.F) {
  		mx = cur;
  	}	
  	else if (cur.F == mx.F) {
  		add(mx.S, cur.S);
  	}
  }
  cout << mx.F << ' ' << mx.S << '\n';
}