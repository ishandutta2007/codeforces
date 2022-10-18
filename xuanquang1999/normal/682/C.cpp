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

int n, a[maxN], mark[maxN], cnt;
ll d[maxN], dist[maxN];
vector<ii> ke[maxN];


void DFS(int u) {
    forit(it, ke[u]) {
        int v = it->ff, w = it->ss;
        d[v] = d[u]+w;
        dist[v] = max((ll)w, dist[u]+w);
        if (dist[v] > a[v]) mark[v] = 1;
        DFS(v);
    }
}

void DFS2(int u) {
    ++cnt;
    forit(it, ke[u]) {
        int v = it->ff;
        if (!mark[v]) DFS2(v);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(u, 2, n) {
        int v, c;
        scanf("%d%d", &v, &c);
        ke[v].pb(mp(u, c));
    }

    DFS(1);
    DFS2(1);

//    fto(u, 1, n) {
//        cout << d[u] << " " << dist[u] << " " << endl;
//    }

    cout << n-cnt;


    return 0;
}