#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 1e5 + 5, M = 1e4 + 5;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

char s[N], t[N];
int x, f[M], g[M];
vector<int> nxt_pos[M];

struct AC {
    int t[M][26], fail[M], isleaf[M], cnt = 0, i, j, base, num;
    queue<int> Q;
    AC(char base0 = 'a', int num0 = 26) { this->base = base0, this->num = num0; }
    void clear() {
        rep(i, 1, cnt) {
            fail[i] = isleaf[i] = 0;
            rep(j, 0, num) t[i][j] = 0;
        }
        cnt = 0;
    }
    void Push(const char *s) {
        //s begins from index 0, not 1
        for (i = 0, j = 0; s[j]; j++) {
            if (!t[i][s[j] - base])
                t[i][s[j] - base] = ++cnt;
            i = t[i][s[j] - base];
        }
        isleaf[i] = 1;
    }
    void Build() {
        for (i = 0; i < num; i++)
            if (t[0][i])
                Q.push(t[0][i]);
        while (!Q.empty()) {
            i = Q.front();
            Q.pop();
            for (j = 0; j < num; j++)
                if (t[i][j])
                    fail[t[i][j]] = t[fail[i]][j],
                    Q.push(t[i][j]);
                else
                    t[i][j] = t[fail[i]][j];
        }
    }
} T('a', 26);

int main() {
    cin >> (s + 1) >> (t + 1);
    int n = strlen(s + 1), nt = strlen(t + 1);
    if (n < nt) {
        cout << 0;
        return 0;
    }

    T.Push(t + 1);
    cerr << T.cnt << " " << nt << endl;
    T.Build();
    rep(j, 0, nt) {
        set<int> tmp;
        rep(x, 0, 25) if (!tmp.count(T.t[j][x]))
            tmp.insert(T.t[j][x]),
            nxt_pos[j].PB(T.t[j][x]);
    }

    rep(j, 1, nt) f[j] = -n - 1;
    f[0] = 0;
    rep(i, 1, n) {
        rep(j, 0, nt) g[j] = -n - 1;
        if (s[i] != '?') {
            int x = s[i] - 'a';
            rep(j, 0, nt) {
                int nxt = T.t[j][x];
                g[nxt] = max(g[nxt], f[j] + (nxt == T.cnt));
            }
        } else {
            rep(j, 0, nt) for (auto nxt : nxt_pos[j])
                g[nxt] = max(g[nxt], f[j] + (nxt == T.cnt));
        }
        swap(f, g);
    }
    int ans = 0;
    rep(j, 0, T.cnt) ans = max(ans, f[j]);
    cout << ans << endl;
    return 0;
}