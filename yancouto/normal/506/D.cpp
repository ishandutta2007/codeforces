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
const int N = 1123456;

int S[N], sz[N], en;

unordered_map<int, int> mp[N];

int true_find(int i) {
	if(S[S[i]] != S[i]) S[i] = true_find(S[i]);
	return S[i];
}

int find(int i, int c) {
	if(mp[i].count(c)) return true_find(mp[i][c]);
	S[en] = en;
	sz[en] = 1;
	mp[i][c] = en;
	//printf("creating %d in %d = %d\n", i, c, en);
	return en++;
}

void join(int a, int b, int c) {
	if((a = find(a, c)) == (b = find(b, c))) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
	//printf("S[%d] = %d\n", b, a);
}

map<pii, int> qs;

int main() {
	int i, n, m, a, b, c;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c); a--; b--;
		//printf("join(%d, %d, %d)\n", a, b, c);
		join(a, b, c);
	}
	for_tests(t, tt) {
		scanf("%d %d", &a, &b); a--; b--;
		if(mp[a].size() < mp[b].size()) swap(a, b);
		if(qs.count(pii(a, b))) { printf("%d\n", qs[pii(a, b)]); continue; }
		int ans = 0;
		for(pii x : mp[b]) {
			if(!mp[a].count(x.fst)) continue;
			//printf("checking %d against %d\n", x.snd, mp[a][x.fst]);
			if(true_find(x.snd) == true_find(mp[a][x.fst]))
				ans++;
		}
		qs[pii(a, b)] = ans;
		printf("%d\n", ans);
	}

}