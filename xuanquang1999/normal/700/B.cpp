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
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, k, a[maxN], f[maxN];
bool visited[maxN], avail[maxN];
vector<int> ke[maxN];
set<int> s1, s2;
ll ans;

void DFS1(int u) {
    if (avail[u]) f[u] = 1;
    visited[u] = true;
    forit(it, ke[u]) {
        int v = *it;
        if (!visited[v]) {
            DFS1(v);
            f[u] += f[v];
        }
    }
}


void DFS(int u) {
    visited[u] = true;
    forit(it, ke[u]) {
        int v = *it;
        if (!visited[v]) {
            ans += min(f[v], f[1]-f[v]);
            DFS(v);
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, 2*k) {
        scanf("%d", &a[i]);
        avail[a[i]] = true;
        s1.insert(a[i]);
    }
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }

    DFS1(1);
//    fto(u, 1, n) printf("%d ", f[u]);
//    puts("");
    memset(visited, false, sizeof visited);
    DFS(1);

    cout << ans;



    return 0;
}