#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second
const int MOD = 1e9 + 7;

pair<string, pair<int, int>> get_pr(string s) {
	int j = 0;
	string name;
	while (s[j] != '(') {
		name.pb(s[j++]);
	}
	j++;
	int x = 0;
	while (s[j] != ',') {
		x = x * 10 + (s[j++] - '0');
	}
	j++;
	int y = 0;
	while (s[j] != ')') {
		y = y * 10 + (s[j++] - '0');
	}
	return make_pair(name, make_pair(x, y));
}

signed main() {
	int n;
	cin >> n;
	int cur_mx = 1;
	map<string, int> x, y, type, len, border, spacing;
	map<string, vector<string>> lol;
	vector<string> names;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "Widget") {
			cin >> s;
			auto kek = get_pr(s);
			//cout << kek.F << ' ' << kek.S.F << ' ' << kek.S.S << '\n';
			x[kek.F] = kek.S.F;
			y[kek.F] = kek.S.S;
			type[kek.F] = 0;
			names.pb(kek.F);
		}
		else if (s == "HBox") {
			cin >> s;
			type[s] = 1;
			names.pb(s);
		}
		else if (s == "VBox") {
			cin >> s;
			type[s] = 2;
			names.pb(s);
		}
		else {
			string name1;
			int j = 0;
			while (s[j] != '.') {
				name1.pb(s[j++]);
			}
			j++;
			if (s[j] == 'p') {
				while (s[j - 1] != '(') {
					j++;
				}
				string name2;
				while (s[j] != ')') {
					name2.pb(s[j++]);
				}
				lol[name1].pb(name2);
				len[name1] = max(len[name1], len[name2] + 1);
				cur_mx = max(cur_mx, len[name1]);
			}
			else {
				while (s[j - 1] != '_') j++;
				if (s[j] == 'b') {
					while (s[j - 1] != '(') {
						j++;
					}
					int vl = 0;
					while (s[j] != ')') {
						vl = vl * 10 + (s[j++] - '0');
					}
					border[name1] = vl; 
				}
				else {
					while (s[j - 1] != '(') {
						j++;
					}
					int vl = 0;
					while (s[j] != ')') {
						vl = vl * 10 + (s[j++] - '0');
					}
					spacing[name1] = vl;
				}
			}
			for (int j = 1; j <= 100; j++) {
				for (string v : names) {
					if (type[v] == 1) {
						x[v] = y[v] = 0;
						for (string u : lol[v]) {
							x[v] += x[u];
							y[v] = max(y[v], y[u]);
						}	
					}
					if (type[v] == 2) {
						x[v] = y[v] = 0;
						for (string u : lol[v]) {
							x[v] = max(x[v], x[u]);
							y[v] += y[u];
						}
					}
					if (!lol[v].empty()) {
						x[v] += 2 * border[v];
						y[v] += 2 * border[v];
						if (type[v] == 1) {
							x[v] += spacing[v] * (SZ(lol[v]) - 1);
						}
						else {
							y[v] += spacing[v] * (SZ(lol[v]) - 1);
						}
					}
				}
			}
		}	
	}
	//cout << '\n';
	sort(all(names));
	for (auto it : names) {
		cout << it << ' ' << x[it] << ' ' << y[it] << '\n';
	}
	cout << '\n';
}