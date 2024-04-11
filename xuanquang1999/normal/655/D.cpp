//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m;
ii e[maxN];

bool Check(int m) {
    vector<int> ke[maxN];
    int deg[maxN];
    memset(deg, 0, sizeof deg);
    fto(i, 1, m) {
        ke[e[i].ff].pb(e[i].ss);
        ++deg[e[i].ss];
    }

    queue<int> q;
    fto(i, 1, n) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        if (q.size() > 1) return false;
        int u = q.front(); q.pop();
        forit(it, ke[u]) {
            int v = *it;
            --deg[v];
            if (deg[v] == 0) q.push(v);
        }
    }
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        scanf("%d%d", &e[i].ff, &e[i].ss);
    }

    int l = 1, r = m, res = r+1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (Check(mid)) {
            res = min(res, mid);
            r = mid-1;
        }
        else l = mid+1;
    }

    if (res > m) cout << -1;
    else cout << res;

    return 0;
}