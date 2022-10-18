//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
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
#define ll long long
#define maxN 1005
#define oo 3000000000000000000LL
#define sz(s) int(s.size())
#define all(s) s.begin(), s.end()

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

void maximize(int &a, int b) {a = max(a, b);}

int n, m, a[maxN];
vector<pair<int, ii> > ke[maxN];
vector<int> x;
bool visited[maxN];

bool DFS(int u, int lo, int hi) {
    if (!visited[u]) {
        visited[u] = true;
        forit(it, ke[u]) {
            int v = it->ff, l = it->ss.ff, r = it->ss.ss;
            if (l <= lo && hi <= r) DFS(v, lo, hi);
        }
    }
}

bool Check(int lo, int hi) {
    memset(visited, false, sizeof visited);
    DFS(1, lo, hi);
    return (visited[n]);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v, l, r;
        scanf("%d%d%d%d", &u, &v, &l, &r);
        ke[u].pb(mp(v, mp(l, r))); ke[v].pb(mp(u, mp(l, r)));
        x.pb(l); x.pb(r);
    }
    sort(x.begin(), x.end());

    int ans = -1;
    fto(i, 0, 2*m-1) {
        int lo = i, hi = 2*m-1, res = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (Check(x[i], x[mid])) {
                res = max(res, mid);
                lo = mid+1;
            }
            else hi = mid-1;
        }
        if (res != -1) maximize(ans, x[res]-x[i]+1);
    }

    if (ans == -1) puts("Nice work, Dima!");
    else printf("%d\n", ans);

    return 0;
}