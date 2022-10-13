#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define x first 
#define y second

using namespace std;

const int N = 300 * 1000 + 13;
const int P = 550;

typedef pair<int, int> pt;

int n;
int a[N];
vector<int> pos[N];
pt ans[N];

int cnt[N];
int tot;

void add(int x){
	++cnt[x];
	if (cnt[x] == 1) ++tot;
}

void rem(int x){
	if (cnt[x] == 1) --tot;
	--cnt[x];
}

int f[N];

void upd(int x){
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		++f[i];
}

int get(int x){
	int res = 0;
	for (int i = x; i < N; i |= i + 1)
		res += f[i];
	return res;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	forn(i, m){
		scanf("%d", &a[i]);
		--a[i];
	}
	forn(i, m){
		pos[a[i]].push_back(i);
	}
	
	vector<pt> qr;
	forn(i, n){
		for (int j = 1; j < int(pos[i].size()); ++j)
			qr.push_back(make_pair(pos[i][j - 1] + 1, pos[i][j] - 1));
		if (!pos[i].empty())
			qr.push_back(make_pair(pos[i].back() + 1, m - 1));
	}
	
	sort(qr.begin(), qr.end(), [](const pt &a, const pt &b){
		if (a.x / P != b.x / P)
			return a.x < b.x;
		if ((a.x / P) & 1)
			return a.y < b.y;
		return a.y > b.y;
	});
	
	forn(i, n) ans[i] = {i, i};
	forn(i, m) ans[a[i]].x = 0;
	
	int L = 0, R = -1;
	forn(i, qr.size()){
		int l = qr[i].x;
		int r = qr[i].y;
		if (r < l) continue;
		
		int x = a[qr[i].x - 1];
		while (L < l) rem(a[L++]);
		while (L > l) add(a[--L]);
		while (R > r) rem(a[R--]);
		while (R < r) add(a[++R]);
		
		ans[x].y = max(ans[x].y, tot);
	}
	forn(i, m){
		if (i == pos[a[i]][0]){
			ans[a[i]].y = max(ans[a[i]].y, a[i] + get(a[i]));
			upd(a[i]);
		}
	}
	forn(i, n) if (pos[i].empty()){
		ans[i].y = max(ans[i].y, i + get(i));
	}
	
	forn(i, n) printf("%d %d\n", ans[i].x + 1, ans[i].y + 1);
	return 0;
}