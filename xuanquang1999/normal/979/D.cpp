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
#define maxX 100005
#define MOD 1000
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

struct Node {
    int nxt[2];
    int minX = maxX;
    Node() {
        fill(begin(nxt), end(nxt), -1);
    }
};

void minimize(int &a, int b) {
    a = min(a, b);
}

int q;
vector<int> divisor[maxX];
vector<Node> t[maxX];
bool added[maxX];

void add(vector<Node> &t, int x) {
    int u = 0;
    minimize(t[u].minX, x);
    fdto(b, 16, 0) {
        int c = (x>>b)&1;
        if (t[u].nxt[c] == -1) {
            t[u].nxt[c] = t.size();
            t.pb({});
        }
        u = t[u].nxt[c];
        minimize(t[u].minX, x);
    }
}

int query(vector<Node> &t, int x, int lim) {
    int u = 0, ans = 0;
    if (t[u].minX > lim) return -1;

    fdto(b, 16, 0) {
        int go = ((x>>b)&1)^1;

        if (t[u].nxt[go] == -1 || t[t[u].nxt[go]].minX > lim)
            go = 1-go;

        ans += go*(1<<b);
        u = t[u].nxt[go];
    }

    return ans;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(x, 1, maxX-1) {
        for(int d = x; d < maxX; d += x) divisor[d].pb(x);
        t[x].pb({});
    }

    scanf("%d", &q);
    fto(i, 1, q) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int u; scanf("%d", &u);
            if (added[u]) continue;

            for(int d: divisor[u]) add(t[d], u);
            added[u] = true;
        } else {
            int x, k, s; scanf("%d%d%d", &x, &k, &s);
            if (x%k != 0 || s < x) {
                puts("-1");
                continue;
            }
            printf("%d\n", query(t[k], x, s-x));
        }
    }

    return 0;
}