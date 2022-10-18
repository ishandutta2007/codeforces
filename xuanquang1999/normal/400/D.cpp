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
#define maxN 200005
#define maxK 505
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

int n, m, k, num[maxN], c[maxK], a[maxK][maxK];
vector<int> t, ke[maxN];

void DFS(int u, int c) {
    num[u] = c;
    forit(it, ke[u]) {
        int v = *it;
        if (!num[v]) DFS(v, c);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 1, k) scanf("%d", &c[i]);

    t.pb(0);
    fto(i, 1, k) {
        fto(j, 1, c[i]) t.pb(i);
    }

    fto(i, 1, k) {
        fto(j, 1, k) a[i][j] = oo;
    }
    fto(u, 1, k) a[u][u] = 0;
    fto(i, 1, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        a[t[u]][t[v]] = a[t[v]][t[u]] = min(a[t[u]][t[v]], c);
        if (c == 0) {ke[u].pb(v); ke[v].pb(u);}
    }

    int cnt = 0;
    fto(u, 1, n) {
        if (!num[u]) DFS(u, ++cnt);
    }

    fto(u, 1, n-1) {
        if (t[u] == t[u+1] && num[u] != num[u+1]) {
            puts("No");
            return 0;
        }
    }


//    fto(u, 1, n) printf("%d ", t[u]);
//    puts("");
//    fto(u, 1, k) {
//        fto(v, 1, k) printf("%d ", a[u][v]);
//        puts("");
//    }


    fto(z, 1, k) {
        fto(u, 1, k) {
            fto(v, 1, k) {
                a[u][v] = min(a[u][v], a[u][z]+a[z][v]);
            }
        }
    }

    puts("Yes");
    fto(u, 1, k) {
        fto(v, 1, k) printf("%d ", (a[u][v] == oo) ? -1 : a[u][v]);
        puts("");
    }

    return 0;
}