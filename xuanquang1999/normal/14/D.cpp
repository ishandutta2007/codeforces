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
#define maxN 205
#define oo 3000000000000000000LL

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

int n, parent[maxN], d[maxN], f[maxN][2], cnt1, cnt2;
bool visited[maxN];
vector<int> ke[maxN];

void DFS(int u) {
    forit(it, ke[u]) {
        int v = *it;
        if (v != parent[u]) {
            parent[v] = u;
            d[v] = d[u]+1;
            DFS(v);
        }
    }
}

void LCA(int u, int v) {
    if (!visited[u]) cnt1 += (visited[u] = true);
    if (!visited[v]) cnt1 += (visited[v] = true);

    if (u == v) return;
    if (d[u] > d[v]) LCA(parent[u], v);
    else if (d[u] < d[v]) LCA(u, parent[v]);
    else LCA(parent[u], parent[v]);
}

void DFS2(int u) {
    visited[u] = true;
    forit(it, ke[u]) {
        int v = *it;
        if (!visited[v]) {
            DFS2(v);
            if (f[v][1]+1 > f[u][1]) {
                f[u][2] = f[u][1];
                f[u][1] = f[v][1]+1;
            }
            else if (f[v][1]+1 > f[u][2]) f[u][2] = f[v][1]+1;
        }
    }
    cnt2 = max(cnt2, f[u][1]+f[u][2]);
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

    DFS(1);

    int ans = 0;
    fto(u, 1, n) {
        fto(v, u+1, n) {
//            printf("u, v: %d %d\n", u, v);
            cnt1 = -1;
            memset(visited, false, sizeof visited);
            memset(f, 0, sizeof f);
            LCA(u, v);
//            debug(cnt1);
            fto(z, 1, n) {
                if (!visited[z]) {
                    cnt2 = 0;
                    DFS2(z);
//                    debug(cnt2);
                    ans = max(ans, cnt1*cnt2);
                }
            }
        }
    }

    printf("%d", ans);


    return 0;
}