#include <iostream>
#include <vector>
using namespace std;

typedef long long s64;

const int MaxM = 1000000;

int m;

inline int nextF(int h, int x, int y) {
	return ((s64)h * x + y) % m;
}

pair<int, int> getF(int h, int x, int y) {
	static bool book[MaxM];
	for (int i = 0; i < m; ++i) {
		book[i] = false;
	}
	
	int l = 0;
	while (!book[h]) {
		book[h] = true;
		h = nextF(h, x, y);
		l++;
	}
	
	int cl = 1;
	for (int i = nextF(h, x, y); i != h; i = nextF(i, x, y)) {
		cl++;
	}
	
	return make_pair(l, cl);
}

int main() {
	int h1, a1, x1, y1;
	int h2, a2, x2, y2;
	
	cin >> m;
	cin >> h1 >> a1 >> x1 >> y1;
	cin >> h2 >> a2 >> x2 >> y2;
	
	pair<int, int> t1 = getF(h1, x1, y1);
	pair<int, int> t2 = getF(h2, x2, y2);
	
	long long cnt = 0;
	
	for (int i = 0; i < max(t1.first, t2.first); i++) {
		if (h1 == a1 && h2 == a2) {
			cout << cnt << endl;
			return 0;
		}
		h1 = nextF(h1, x1, y1);
		h2 = nextF(h2, x2, y2);
		cnt++;
	}
	
	int p = 0;
	while (p < t1.second && h1 != a1) {
		h1 = nextF(h1, x1, y1);
		h2 = nextF(h2, x2, y2);
		cnt++;
		p++;
	}
	if (p == t1.second) {
		cout << -1 << endl;
		return 0;
	}
	if (h2 == a2) {
		cout << cnt << endl;
		return 0;
	}
	
	vector<int> vec;
	for (int i = 0, ch = h2; i < t2.second; i++, ch = nextF(ch, x2, y2)) {
		vec.push_back(ch);
	}
	
	int h2p = 0;
	do
		h2p = (h2p + t1.second) % t2.second, cnt += t1.second;
	while (h2p != 0 && vec[h2p] != a2);
	
	if (h2p == 0) {
		cout << -1 << endl;
		return 0;
	}
	
	cout << cnt << endl;
	
	return 0;
}