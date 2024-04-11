#include <bits/stdc++.h>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define Out(i, a, b) for (int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <long double, long double>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)
//#define _CRT_DISABLE_PERFCRIT_LOCKS
using namespace std;

typedef long long base;
const int MAXN = 1e5 + 1;
int n, m, m10;

int fpn(int p, int n) {
    if (n == 0) return 1;
    return pow(p, n) - pow(p, n - 1);   
}

int f(base n) {
	base i = 2;
	base ans = 1;
	while (i * i <= n) {
        int cnt = 0;
    	while (n % i == 0) {
            ++cnt;
    		n /= i;
	    }
	    ans *= fpn(i, cnt);
		++i;
	}
	if (n != 1) ans *= (n - 1);
	return ans; 
}

int sum(int a, int b) {
	a += b;
	if (a >= m)
		a -= m;
	return a;
}

int fast_pow(base i, int j) {
	base ans = 1;
	while (j) {
		if (j & 1) ans = (ans * i) % m;
		i = (i * i) % m;
		j >>= 1;
	}
	return ans;
} 

bool used[MAXN];
int s[MAXN];
int comp[MAXN];
int dist[MAXN];
int a[MAXN], b[MAXN];
vector <int> cost[MAXN];
vector <int> edge[MAXN];

void dfs(int i, int p, vector <int> &que) {
    s[i] = 1;
    if (p == -1) comp[i] = -1, a[i] = 0, b[i] = 0, dist[i] = 0;
    que.pb(i);
    For(k, 0, edge[i].size()) {
        int j = edge[i][k];
        int c = cost[i][k];
        if (p == j || used[j]) continue;
        if (p == -1) comp[j] = j;
        else comp[j] = comp[i];
        dist[j] = dist[i] + 1;
        a[j] = ((base)a[i] * 10 + c) % m;
        b[j] = ((base)b[i] * m10 + c) % m;
        dfs(j, i, que);
        s[i] += s[j];
    }
}

base ans = 0;
map <int, int> cnt[2];

void centroid_dec(int i) {
    if (used[i]) return;
    vector <int> que;
    used[i] = true;
    dfs(i, -1, que);
    base f10 = 1, d10 = 0;
    base fm10 = 1, dm10 = 0;
    For(k, 0, 2) {
        For(j, 0, que.size()) {
            if (j != 0 && comp[que[j]] != comp[que[j - 1]]) {
                int R = j - 1;
                while (true) {
                	while (d10 < dist[que[R]]) f10 = (f10 * 10) % m, ++d10;
                	while (d10 > dist[que[R]]) f10 = (f10 * m10) % m, --d10;
                    ++cnt[k][f10 * b[que[R]] % m * m10 % m];
                    if (R == 0 || comp[que[R - 1]] != comp[que[R]])
                        break;
                    --R;
                }
            }
            while (dm10 < dist[que[j]]) fm10 = (fm10 * m10) % m, ++dm10;
            while (dm10 > dist[que[j]]) fm10 = (fm10 * 10) % m, --dm10;
            ans += cnt[k][fm10 * (m - a[que[j]]) % m];
        }
        reverse(que.begin(), que.end());
    }
    cnt[0].clear();
    cnt[1].clear();
    Out(j, (int)que.size(), 0) {
    	if (used[que[j]]) continue;
    	if (s[que[j]] * 2 >= s[comp[que[j]]]) {
    		centroid_dec(que[j]);
    	}
    }
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	if (m == 1) {
	    cout << (base)n * (n - 1) << endl;
	    return 0;
	}
	m10 = fast_pow(10, f(m) - 1);
	For(i, 0, n - 1) {
		int s, f, c;
		cin >> s >> f >> c;
		edge[s].pb(f);
		edge[f].pb(s);
		cost[s].pb(c);
		cost[f].pb(c);
	}
	centroid_dec(0);
	cout << ans << endl;
}