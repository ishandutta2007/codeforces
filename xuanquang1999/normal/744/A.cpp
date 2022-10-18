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
#define maxK 20
#define oo 1000000007

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

int n, m, p, cntV, cntE, freeE, freeV;
vector<int> ke[maxN];
bool gov[maxN], visited[maxN], haveGov;
vector<ii> cc;

void DFS(int u) {
    if (gov[u]) haveGov = true;
    ++cntV;
    visited[u] = true;
    forit(it, ke[u]) {
        ++cntE;
        int v = *it;
        if (!visited[v]) DFS(v);
    }
}

int trinum(int x) {
    return x*(x-1)/2;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &p);
    fto(i, 1, p) {
        int x;
        scanf("%d", &x);
        gov[x] = true;
    }
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }

    fto(u, 1, n) {
        if (!visited[u]) {
            cntV = cntE = 0;
            haveGov = false;
            DFS(u);
            cntE /= 2;
            if (haveGov) cc.pb(mp(cntV, cntE));
            else freeV += cntV, freeE += cntE;
        }
    }

    int ans = 0;
    forit(it, cc) {
        int v = it->ff, e = it->ss;
        ans = max(ans, trinum(freeV+v)-freeE-trinum(v));
    }

    forit(it, cc) {
        int v = it->ff, e = it->ss;
        ans += trinum(v)-e;
    }

    cout << ans;

    return 0;
}