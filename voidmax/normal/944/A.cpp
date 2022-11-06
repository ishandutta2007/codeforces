#include <bits/stdc++.h>
#define x fisrt
#define y second
#define pb push_back
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
using namespace std;

typedef pair<int, int> point;

const string FILENAME = "input";

int n, a, b;

int main() {
	ios::sync_with_stdio(false);
	//read(FILENAME);
	cin >> n >> a >> b;
	--a, --b;
	int cnt = 0, p = 0;
	while ((1 << p) < n) ++p;
	for (int i = p; --i;) {
		if ((a >> i) == (b >> i)) {
			++cnt;
		} else {
			break;
		}
	}
	//cout << p << ' ' << cnt << endl;
	if (cnt == 0) {
		cout << "Final!" << endl;
	} else {
		cout << p - cnt << endl;
	}

}