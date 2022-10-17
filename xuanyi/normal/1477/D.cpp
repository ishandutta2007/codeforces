#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 5e5 + 5;

priority_queue <pii> Q;
map <pii, int> mp;
vector <int> res[N];
queue <int> q;
int fa[N], seq[N], dep[N], ansp[N], ansq[N];
int T, n, m, len, tot;

bool chk(int u, int v) {
    if (u > v) swap(u, v);
    return mp.count(make_pair(u, v)) ^ 1;
}

int main() {
    read(T);
    while (T--) {
        mp.clear();
        read(n); read(m); tot = 0;
        for (int i = 1; i <= n; i++) res[i].clear(), fa[i] = 0;
        for (int i = 1; i <= m; i++) {
            int u, v;
            read(u); read(v);
            if (u > v) swap(u, v);
            mp[make_pair(u, v)] = 1;
        }
        len = n;
        for (int i = 1; i <= n; i++) seq[i] = i;
        while (len) {
            int rt = seq[len]; --len;
            q.push(rt); dep[rt] = 0;
            vector <int> lt;
            while (!q.empty()) {
                int u = q.front(); q.pop(); lt.push_back(u);
                vector <int> new_seq;
                for (int i = len; i >= 1; i--) {
                    if (chk(u, seq[i])) {
                        q.push(seq[i]);
                        fa[seq[i]] = u;
                        dep[seq[i]] = dep[u] + 1;
                        Q.push(make_pair(dep[seq[i]], seq[i]));
                    } else new_seq.push_back(seq[i]);
                }
                len = (int)new_seq.size();
                for (int i = 1; i <= len; i++) seq[i] = new_seq[i - 1];
            }
            if (lt.size() == 1) {
                ansp[rt] = ansq[rt] = ++tot;
                continue;
            }
            while (!Q.empty()) {
                pii u = Q.top(); Q.pop();
                if (!res[u.second].size()) res[fa[u.second]].push_back(u.second);
            }
            if (!res[rt].size()) {
                for (int i = 0; i < (int)lt.size(); i++) {
                    if (fa[lt[i]] == rt) {
                        res[lt[i]].push_back(rt);
                        break;
                    }
                }
            }
            for (int i = 0; i < (int)lt.size(); i++) {
                if (res[lt[i]].size()) {
                    for (int j = 0; j < (int)res[lt[i]].size(); j++) ansp[res[lt[i]][j]] = tot + 1 + j, ansq[res[lt[i]][j]] = tot + 2 + j;
                    ansp[lt[i]] = tot + (int)res[lt[i]].size() + 1; ansq[lt[i]] = tot + 1; tot += (int)res[lt[i]].size() + 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) print(ansp[i], i == n ? '\n' : ' ');
        for (int i = 1; i <= n; i++) print(ansq[i], i == n ? '\n' : ' ');
    }
    return 0;
}