#include <bits/stdc++.h>
#define x fisrt
#define y second
#define pb push_back
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
using namespace std;

typedef pair<int, int> point;

const string FILENAME = "input";

const int MAXN = 2e5;

int n;
int rep = 1e9;
int a[3], b[3], ans[3], mx = 1e9, maxv = -1e9;
int arr[MAXN];

int main() {
	ios::sync_with_stdio(false);
	// /read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		mx = min(mx, arr[i]);
		maxv = max(maxv, arr[i]);
	}
	if (maxv - mx < 2) {
		cout << n << endl;
		for (int i = 0; i < n; ++i) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		arr[i] -= mx;
		a[arr[i]]++;
	}
	b[0] = a[0];
	b[1] = a[1];
	b[2] = a[2];
	b[1] += b[2] * 2;
	b[0] -= b[2];
	b[2] = 0;
	for (int i = 0; i <= n; ++i) {
		if (b[0] >= 0 && b[1] >= 0 && b[2] >= 0) {
			int nans = 0;
			for (int j = 0; j < 3; ++j) {
				nans += min(a[j], b[j]);
			}
			if (rep > nans) {
				rep = nans;
				for (int j = 0; j < 3; ++j) {
					ans[j] = b[j];
				}
			}
		}
		++b[2];
		++b[0];
		b[1] -= 2;
	}
	cout << rep << '\n';
	for (int j = 0; j < 3; ++j) {
		for (int q = 0; q < ans[j]; ++q) {
			cout << mx + j << ' ';
		}
	}
	cout << '\n';
}