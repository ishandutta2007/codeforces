#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int T, n, m, x, y, A[N], tot;
long long who[N];
char s[N];

map < long long, int> Map;

vector < int > v[N];

string ans;

int main() {
	int T;
	scanf("%d", &n);
	scanf("%s", s + 1);
	int j = 0;
	for(int i = 1; i <= n; ++ i) {
		if(s[i] == '1') {
			j = i; break;
		}
	}
	if(j == 0) {
		puts("0");
		return 0;
	}
	
//	cerr << j << endl;
	
	int k = 0;
	
	for(int i = j; i <= n; ++ i) if(s[i] == '0') {
		k = i; break;
	}
	
	if(!k) {
		for(int i = j; j <= n; ++ j) printf("1");
		puts("");
		return 0;
	}
	
	// k - n will be good
	
	int now = min(n - k + 1, 62);
	long long ret = 0;
	
	for(int i = k; i <= k + now - 1; ++ i) {
		ret = ret * 2 + s[i] - '0';
	}
	
//	cerr << ret << endl;
	
	for(int i = 1; i <= k; ++ i) {
		long long cur = 0;
		for(int j = i; j <= i + now - 1; ++ j)
		cur = (cur * 2) + s[j] - '0';
		if(!Map.count(cur)) {
			Map[cur] = ++ tot;
			who[tot] = cur;
		}
		int h = Map[cur];
		v[h].push_back(i);
	}
	
	long long mx = 0;
	
	for(int i = 1; i <= tot; ++ i) {
		mx = max(mx, (who[i] | ret));
	}
	
	ans = "";
	for(int i = j; i <= n; ++ i) ans.push_back(s[i]);
	
	string nw = ans;
	
	for(int i = 1; i <= tot; ++ i) {
		if((who[i] | ret) == mx) {
			for(auto x : v[i]) {
//				cerr << x << ' ' << mx << ' ' << nw << ' ' << who[i] <<  endl;
				string tmp = nw;
				for(int jj = x; jj <= x + (n - k); ++ jj) {
					if(s[jj] == '1') {
						tmp[jj - x + (k - j)] = '1';
					}
				}
				ans = max(ans, tmp);
			}
		}
	}
	cout << ans << endl;
}