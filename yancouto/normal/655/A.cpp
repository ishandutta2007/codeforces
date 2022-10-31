#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

char g[2][2];

int id() {
	int x = 0;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			x = 26 * x + (g[i][j] - 'A');
	return x;
}

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < 2 && j < 2; }

set<int> s, s1;
void proc() {
	if(s.count(id())) return;
	s.insert(id());
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			if(g[i][j] == 'X') {
				for(int d = 0; d < 4; d++) {
					int ni = i + di[d], nj = j + dj[d];
					if(!valid(ni, nj)) continue;
					swap(g[i][j], g[ni][nj]);
					proc();
					swap(g[i][j], g[ni][nj]);
				}
				return;
			}
}

int main() {
	int i, j, n;
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			scanf(" %c", &g[i][j]);
	proc();
	s1.swap(s);
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			scanf(" %c", &g[i][j]);
	proc();
	if(s.size() != s1.size()) { puts("NO"); return 0; }
	for(int x : s)
		if(!s1.count(x)) {
			puts("NO");
			return 0;
		}
	puts("YES");
}