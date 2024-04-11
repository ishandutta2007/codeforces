//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ftoa(i, l, r, a) for(int i = (l); i <= (r); i += a)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define MOD 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

int n, c[maxN], cnt[maxN], f[maxN];
vector<int> ke[maxN];
bool ok[maxN];

void DFS(int u, int p) {
    bool ans = true;
    ok[u] = true; f[u] = 1;
    int cntCP = 0;

    forit(it, ke[u]) {
        int v = *it;
        if (v != p) {
            DFS(v, u);
            if (!ok[v]) {
                ans = false;
                ok[u] = false;
            }
            if (c[v] != c[u]) ok[u] = false;
            f[u] += f[v];

            if (p != -1 && c[p] == c[v]) {
                cntCP += f[v];
            }
        }
    }
    if (c[u] == c[p]) ++cntCP;
    if (ans && (p == -1 || cnt[c[p]]-cntCP == n-f[u])) {
        puts("YES");
        printf("%d", u);
        exit(0);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }
    fto(u, 1, n) scanf("%d", &c[u]), ++cnt[c[u]];

    DFS(1, -1);
    puts("NO");

    return 0;
}