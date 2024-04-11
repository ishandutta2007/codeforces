#include <bits/stdc++.h>

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int(a.size())

#define x first
#define y second

using namespace std;

const int B = 2;

typedef array<int, B> ht;

ht MOD, BASE;

inline int norm(int a, const int &MOD) {
	while(a >= MOD)
		a -= MOD;
	while(a < 0)
		a += MOD;
	return a;
}

inline int mul(int a, int b, const int &MOD) {
	return int(a * 1ll * b % MOD);
}

inline ht operator +(const ht &a, const ht &b) {
	ht ans;
	fore(i, 0, sz(ans))
		ans[i] = norm(a[i] + b[i], MOD[i]);
	return ans;
}

inline ht operator -(const ht &a, const ht &b) {
	ht ans;
	fore(i, 0, sz(ans))
		ans[i] = norm(a[i] - b[i], MOD[i]);
	return ans;
}

inline ht operator *(const ht &a, const ht &b) {
	ht ans;
	fore(i, 0, sz(ans))
		ans[i] = mul(a[i], b[i], MOD[i]);
	return ans;
}

int CMODS[] = {int(1e9) + 7, int(1e9) + 9, int(1e9) + 21, int(1e9) + 33, int(1e9) + 87, int(1e9) + 93, int(1e9) + 97, int(1e9) + 103};
int CBASE[] = {1009, 1013, 1019, 1021};

const int N = 200 * 1000 + 555;

int n, m;
char s[N];
int x[N], y[N], len[N];

inline bool read() {
	if(!(cin >> n >> m))
		return false;
	assert(scanf("%s", s) == 1);
	
	fore(i, 0, m) {
		assert(scanf("%d%d%d", &x[i], &y[i], &len[i]) == 3);
		x[i]--, y[i]--;
	}
	return true;
}
void setMods() {
	mt19937 rnd;
	unsigned int seed = n;
	fore(i, 0, n)
		seed = (seed * 3) + s[i];
	fore(i, 0, m) {
		seed = (seed * 3) + x[i];
		seed = (seed * 3) + y[i];
		seed = (seed * 3) + len[i];
	}
	rnd.seed(seed);
	
	set<int> mids;
	while(sz(mids) < sz(MOD))
		mids.insert(rnd() % 8);
	vector<int> vmids(mids.begin(), mids.end());
	fore(i, 0, sz(MOD)) {
		MOD[i] = CMODS[vmids[i]];
		BASE[i] = CBASE[i];
	}
}

ht pBase[N];
ht ph[27][N];
vector<int> ord[N];

ht getHash(int id, int l, int r) {
	return ph[id][r] - ph[id][l] * pBase[r - l];
}

inline void solve() {
	setMods();
	
	pBase[0] = {1, 1};
	fore(i, 1, N)
		pBase[i] = pBase[i - 1] * BASE;
		
	fore(c, 0, 26) {
		ph[c][0] = {0, 0};
		fore(i, 0, n) {
			int val = (s[i] == c + 'a');
			ph[c][i + 1] = ph[c][i] * BASE + ht{val, val};
		}
	}
	
	vector<int> curOrd(26, 0);
	iota(curOrd.begin(), curOrd.end(), 0);
	for(int i = n - 1; i >= 0; i--) {
		ord[i] = curOrd;
		auto it = find(ord[i].begin(), ord[i].end(), int(s[i] - 'a'));
		ord[i].erase(it);
		ord[i].insert(ord[i].begin(), int(s[i] - 'a'));
		curOrd = ord[i];
	}
	
	fore(q, 0, m) {
		int s1 = x[q], s2 = y[q];
		bool ok = true;
		
		fore(i, 0, 26) {
			if(getHash(ord[s1][i], s1, s1 + len[q]) != 
				getHash(ord[s2][i], s2, s2 + len[q])) {
				ok = false;
				break;
			}
		}
		puts(ok ? "YES" : "NO");
	}
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	if(read()) {
		solve();
	}
	return 0;
}