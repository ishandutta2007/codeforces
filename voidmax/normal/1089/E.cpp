#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define len(v) ((int)v.size())
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
	for (T x : v) {
		os << x << " ";
	}
	return os;
}

template <class T>
istream &operator>>(istream &is, vector<T> &v) {
	for (T &x : v) {
		is >> x;
	}
	return is;
}

void run();

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	run();
}

int N = 8;
#define endl " "

vector<vector<bool>> used(N, vector<bool>(N));

string conv(int x, int y) {
	string s;
	s += 'a' + y;
	s += x + '1';
	return s;
}

void run() {
	int k;
	cin >> k;
	cout << "a1" << endl;
	pii cur = mp(0, 0);
	used[0][0] = true;
	while (k > 3 && cur.x < 7) {
		int next = -1;
		for (int i = N - 1; i > -1; i--) {
			if (!used[cur.x][i]) {
				next = i;
				break;
			}
		}
		if (next == -1) {
			cur.x++;
			used[cur.x][cur.y] = true;
		} else {
			used[cur.x][next] = true;
			cur = mp(cur.x, next);
		}
		cout << conv(cur.x, cur.y) << endl;
		k--;
	}
	if (k == 3) {
		vector<pii> free;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!used[i][j]) {
					free.emplace_back(i, j);
				}
			}
		}
		for (pii A : free) {
			for (pii B : free) {
				if (A == B) continue;
				if (A == mp(7, 7)) continue;
				if (B == mp(7, 7)) continue;
				if (A.x == B.x || A.y == B.y) {
					if (B.y == 7 || B.x == 7) {
						if (cur.x == A.x || cur.y == A.y) {
							cout << conv(A.x, A.y) << endl;
							cout << conv(B.x, B.y) << endl;
							cout << conv(7, 7) << endl;
							return;
						}
					}
				}
			}
		}
	} else {
		while (k > 1) {
			int next = -1;
			for (int i = 0; i < N; i++) {
				if (!used[7][i]) {
					next = i;
					break;
				}
			}
			used[7][next] = true;
			cur = mp(7, next);
			cout << conv(7, next) << endl;
			k--;
		}		
	}
	cout << conv(7, 7) << endl;
}