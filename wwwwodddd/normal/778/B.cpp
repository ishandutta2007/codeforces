#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <map>
using namespace std;
int n, m;
vector<int> a[5020];
string minans;
string maxans;
char shabima[5020][1020];
int g[5020];
int main() {
	cin >> n >> m;	
	string s;
	getline(cin, s);
	map<string, int>dic;
	dic["?"] = 0;
	for (int i = 1; i <= n; i++) {
		getline(cin, s);
		string r;
		vector<string> tmd;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ' ') {
				tmd.push_back(r);
				r = "";
			} else {
				r += s[j];
			}
		}
		tmd.push_back(r);
		r = "";
		dic[tmd[0]] = i;
		if (tmd.size() == 3) {
			a[i].push_back(i);
			a[i].push_back(0);
			for (int j = 0; j < m; j++) {
				shabima[i][j] = tmd[2][j];
			}
		} else {
			a[i].push_back(i);
			a[i].push_back(0);
			a[i].push_back(dic[tmd[2]]);
			if (tmd[3] == "OR") {
				a[i].push_back(3);
			} else if (tmd[3] == "AND") {
				a[i].push_back(4);
			} else if (tmd[3] == "XOR") {
				a[i].push_back(5);
			}
			a[i].push_back(dic[tmd[4]]);

		}
//		for (int j = 0; j < a[i].size(); j++) {
//			cout << "???" << i << ' ' << a[i][j] << endl;
//		}
	}
	for (int j = 0; j < m; j++) {
		int sum0 = 0;
		int sum1 = 0;
		{
			g[0] = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i].size() == 2) {
					g[a[i][0]] = shabima[i][j] - '0';
				} else if (a[i].size() == 5) {
					if (a[i][3] == 3) {
						g[a[i][0]] = g[a[i][2]] | g[a[i][4]];
					} else if (a[i][3] == 4) {
						g[a[i][0]] = g[a[i][2]] & g[a[i][4]];
					} else if (a[i][3] == 5) {
						g[a[i][0]] = g[a[i][2]] ^ g[a[i][4]];
					} else {
						assert(false);
					}
				} else { 
					assert(false);
				}
				sum0 += g[a[i][0]];
			}
//			cout << g["c"] << endl;
		}
		{
			g[0] = 1;
			for (int i = 1; i <= n; i++) {
				if (a[i].size() == 2) {
					g[a[i][0]] = shabima[i][j] - '0';
				} else if (a[i].size() == 5) {
					if (a[i][3] == 3) {
						g[a[i][0]] = g[a[i][2]] | g[a[i][4]];
					} else if (a[i][3] == 4) {
						g[a[i][0]] = g[a[i][2]] & g[a[i][4]];
					} else if (a[i][3] == 5) {
						g[a[i][0]] = g[a[i][2]] ^ g[a[i][4]];
					} else {
						assert(false);
					}
				} else { 
					assert(false);
				}
				sum1 += g[a[i][0]];
			}
//			cout << g["c"] << endl;
		}
//		cout << sum0 << ' ' << sum1 << endl;
		if (sum0 == sum1) {
			minans += "0";
			maxans += "0";
		} else if (sum0 > sum1) {
			minans += "1";
			maxans += "0";
		} else if (sum0 < sum1) {
			minans += "0";
			maxans += "1";
		}
	}
	cout << minans << endl;
	cout << maxans << endl;
	return 0;
}