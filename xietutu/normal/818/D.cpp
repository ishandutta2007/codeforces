#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef unsigned int ui;
#define PB push_back
#define MP make_pair
#define F first
#define S second
const int maxn = 1000010;
int n, A, ret, cnt[maxn], c[maxn];
set<pii> T;
bool vis[maxn];
int main() {
	scanf("%d%d", &n, &A);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", c + i);
		if (c[i] != A) {
			T.insert(pii(0, c[i]));
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (c[i] == A) {
			++ret;
			for (auto it = T.begin(); it != T.end(); ) {
				if (it->F < ret) {
					vis[it->S] = true;
					T.erase(it++);
				}
				else break;
			}
		}
		else {
			if (!vis[c[i]]) {
				T.erase(pii(cnt[c[i]], c[i]));
				++cnt[c[i]];
				T.insert(pii(cnt[c[i]], c[i]));
			}
		}
	}
	if (T.size()) {
		cout << T.begin()->second << endl;
	}
	else cout << -1 << endl;
}