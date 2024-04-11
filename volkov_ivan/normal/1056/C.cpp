#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_N = 2e3 + 7;
int p[MAX_N], pa[MAX_N];
bool is_simple[MAX_N], fi[MAX_N];
bool used[MAX_N];
set <pair <int, int>, greater <pair <int, int>>> simple;
set <pair <int, int>> bip;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 2 * n; i++) cin >> p[i];
	for (int i = 1; i <= 2 * n; i++){ used[i] = 0; is_simple[i] = fi[i] = 1;}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		is_simple[a] = 0;
		is_simple[b] = 0;
		pa[a] = b;
		pa[b] = a;
		fi[b] = 0;
		bip.insert(make_pair(a, b));
	}
	for (int i = 1; i <= 2 * n; i++) if (is_simple[i]) simple.insert(make_pair(p[i], i));
	int t;
	int last = -1;
	cin >> t;
	for (int i = 0; i < 2 * n; i++) {
		if (((i % 2 == 0) && (t == 1)) || ((i % 2 == 1) & (t == 2))) {
			if (last != -1 && !is_simple[last] && !used[pa[last]]) {
				cout << pa[last] << endl;	
				used[pa[last]] = 1;
			} else {
				if (!bip.empty()) {
					pair <int, int> elem = *bip.begin();
					if (p[elem.first] > p[elem.second]) {used[elem.first] = 1, cout << elem.first << endl;}
					else {used[elem.second] = 1; cout << elem.second << endl;}
				} else {
					pair <int, int> elem = *simple.begin();
					simple.erase(elem);
					cout << elem.second << endl;
					used[elem.second] = 1;
				}
			}
		} else {
			cin >> last;
			used[last] = 1;
			if (is_simple[last]) {
				simple.erase(make_pair(p[last], last));
			} else {
				if (fi[last]) bip.erase(make_pair(last, pa[last]));
				else bip.erase(make_pair(pa[last], last));
			}
		}
	}
	return 0;
}