//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 505
#define maxM 100005
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

ll mul(ll a, ll b) {
    if (a*b/a != b) return oo;
    return min(oo, a*b);
}

void read(vector<int> &a) {
    string s; cin >> s;
    fto(i, 0, sz(s)-1) a.pb(s[i]-'0');
}

struct edge {
    int u, v;
    bool flag, avail;
};

int n, m, par[maxN], parID[maxN], state[maxN];
edge e[maxM];
vector<int> g[maxN];
bool found, flagging;

void DFS(int u) {
    if (found) return;
    state[u] = 1;
//    debug(u);
    for(int i: g[u]) {
        if (found) return;

        if (!e[i].avail) continue;
        int v = e[i].u+e[i].v-u;

        if (state[v] == 1) {
            found = true;
            if (flagging) {
                e[i].flag = true;
                while (u != v) {
                    e[parID[u]].flag = true;
                    u = par[u];
                }
            }
            return;
        } else if (state[v] == 0) {
            par[v] = u;
            parID[v] = i;
            DFS(v);
        }
    }

    state[u] = 2;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        scanf("%d%d", &e[i].u, &e[i].v);
        g[e[i].u].pb(i);
        e[i].avail = true;
    }

    flagging = true;
    fto(u, 1, n) {
        if (state[u] == 0) DFS(u);
    }

//    debug(found);
//    fto(i, 1, m) printf("%d %d %d %d\n", e[i].u, e[i].v, e[i].flag, e[i].avail);

    if (!found) {
        puts("YES");
        return 0;
    }

    flagging = false;
    fto(i, 1, m) {
        if (e[i].flag) {
            found = false;
            fill(par+1, par+n+1, 0);
            fill(state+1, state+n+1, 0);
            e[i].avail = false;

            fto(u, 1, n) {
                if (state[u] == 0) {
//                    printf("%d\n", u);
                    DFS(u);
                }
            }
            if (!found) {
                puts("YES");
                return 0;
            }

            e[i].avail = true;
        }
    }

    puts("NO");

    return 0;
}