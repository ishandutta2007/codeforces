#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

void print(const vector<string> &s) {
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << endl;
	}
	cout << endl;
}
vector<pair<int, int> > solve(vector<string> s) {
	vector<pair<int, int> > re;
	int n = s.size();
	int m = s[0].size();
	int last = -1;
//	print(s);
	while (true) {
		for (int i = 0; i + 1 < n; i++) {
			for (int j = 0; j + 2 < m; j++) {
				if (0<i&&i+1<n-1&&j+1>0&&j+2<m-1 && s[i][j] == 'U' && s[i + 1][j] == 'D' && s[i][j + 1] == 'L' && s[i + 1][j + 1] == 'L' && s[i][j + 2] == 'R' && s[i + 1][j + 2] == 'R') {
					s[i][j + 1] = s[i][j + 2] = 'U';
					s[i + 1][j + 1] = s[i + 1][j + 2] = 'D';
					re.push_back(make_pair(i, j + 1));
				}
				if (0<i&&i<n-1&&j>0&&j<m-1 && s[i][j] == 'L' && s[i + 1][j] == 'L' && s[i][j + 1] == 'R' && s[i + 1][j + 1] == 'R' && s[i][j + 2] == 'U' && s[i + 1][j + 2] == 'D') {
					s[i][j] = s[i][j + 1] = 'U';
					s[i + 1][j] = s[i + 1][j + 1] = 'D';
					re.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i + 2 < n; i++) {
			for (int j = 0; j + 1 < m; j++) {
				if (0<i+1&&i+2<n-1&&j>0&&j+1<m-1 && s[i][j] == 'L' && s[i][j + 1] == 'R' && s[i + 1][j] == 'U' && s[i + 1][j + 1] == 'U' && s[i + 2][j] == 'D' && s[i + 2][j + 1] == 'D') {
					s[i + 1][j] = s[i + 2][j] = 'L';
					s[i + 1][j + 1] = s[i + 2][j + 1] = 'R';
					re.push_back(make_pair(i + 1, j));
				}
				if (0<i&&i+1<n-1&&j>0&&j+1<m-1 && s[i][j] == 'U' && s[i][j + 1] == 'U' && s[i + 1][j] == 'D' && s[i + 1][j + 1] == 'D' && s[i + 2][j] == 'L' && s[i + 2][j + 1] == 'R') {
					s[i][j] = s[i + 1][j] = 'L';
					s[i][j + 1] = s[i + 1][j + 1] = 'R';
					re.push_back(make_pair(i, j));
				}
			}
		}
		if (last == re.size()) {
			break;
		}
		last = re.size();
//		print(s);
//		cout << re.size() << endl;
	}
	return re;
}
string s[100];
string t[100];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	if (m % 2 == 1) {
		vector<string>as;
		vector<string>at;
		string tmdu = "";
		string tmdd = "";
		for (int i = 0; i < m + 2; i++) {
			tmdu += "U";
			tmdd += "D";
		}
		as.push_back(tmdu);
		as.push_back(tmdd);
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 1) {
				as.push_back("U" + s[i] + "U");
			} else {
				as.push_back("D" + s[i] + "D");
			}
		}
		as.push_back(tmdu);
		as.push_back(tmdd);
		at.push_back(tmdu);
		at.push_back(tmdd);
		for (int i = 1; i <= n; i++) {
			if (i % 2 == 1) {
				at.push_back("U" + t[i] + "U");
			} else {
				at.push_back("D" + t[i] + "D");
			}
		}
		at.push_back(tmdu);
		at.push_back(tmdd);
		vector<pair<int, int> >bs = solve(as);
		vector<pair<int, int> >bt = solve(at);
		cout << bs.size() + bt.size() << endl;
		for (int i = 0; i < bs.size(); i++) {
			printf("%d %d\n", bs[i].first - 1, bs[i].second);	
		}
		for (int i = bt.size() - 1; i >= 0; i--) {
			printf("%d %d\n", bt[i].first - 1, bt[i].second);
		}
	} else {
		vector<string>as;
		vector<string>at;
		string tmd = "";
		for (int i = 0; i < m + 4; i += 2) {
			tmd += "LR";
		}
		as.push_back(tmd);
		for (int i = 1; i <= n; i++) {
			as.push_back("LR" + s[i] + "LR");
		}
		as.push_back(tmd);
		at.push_back(tmd);
		for (int i = 1; i <= n; i++) {
			at.push_back("LR" + t[i] + "LR");
		}
		at.push_back(tmd);
		vector<pair<int, int> >bs = solve(as);
		vector<pair<int, int> >bt = solve(at);
		cout << bs.size() + bt.size() << endl;
		for (int i = 0; i < bs.size(); i++) {
			printf("%d %d\n", bs[i].first, bs[i].second - 1);	
		}
		for (int i = bt.size() - 1; i >= 0; i--) {
			printf("%d %d\n", bt[i].first, bt[i].second - 1);
		}
	}
}