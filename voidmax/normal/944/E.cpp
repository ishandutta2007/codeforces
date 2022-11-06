#include <bits/stdc++.h>
#define x fisrt
#define y second
#define pb push_back
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
using namespace std;

typedef pair<int, int> point;

const string FILENAME = "input";

const int MAXN = 2e5;

int n, m;
int arr[MAXN];
int lst;
int w[MAXN];
int L[MAXN], R[MAXN];

int main() {
	ios::sync_with_stdio(false);
	//read(FILENAME);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int L, R;
		cin >> L >> R;
		--L, --R;
		arr[L]++;
		arr[R + 1]--;
	}
	for (int i = 1; i < m; ++i) {
		arr[i] += arr[i - 1];
	}
	for (int t = 0; t < 2; ++t) {
		lst = 0;
		memset(w, 0, sizeof(w));
		for (int i = 0; i < m; ++i) {
			int L = 0, R = lst + 1;
			while (R - L > 1) {
				int M = (L + R) >> 1;
				if (w[M] <= arr[i]) {
					L = M;
				} else {
					R = M;
				}
			}
			if (t == 0) {
				::L[i] = L;
			} else {
				::R[i] = R;
			}
			if (lst == L) {
				++lst;
				w[lst] = arr[i];
			} else {
				w[L + 1] = min(w[L + 1], arr[i]);
			}
		}
		reverse(arr, arr + m);
		reverse(R, R + m);
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		//cout << L[i] << ' ' << R[i] << endl;
		ans = max(ans, L[i] + R[i]);
	}
	cout << ans << endl;
}