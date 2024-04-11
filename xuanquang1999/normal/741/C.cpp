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

bool isPrime(int n) {
    if (n < 2) return false;
    int lim = sqrt(n);
    fto(i, 2, lim) {
        if (n%i == 0) return false;
    }
    return true;
}

int n, color[maxN];
vector<int> ke[maxN];
vector<ii> e;

void DFS(int u, int c) {
    color[u] = c;
    forit(it, ke[u]) {
        int v = *it;
        if (!color[v]) DFS(v, 3-c);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
        e.pb(mp(u, v));
    }
    fto(i, 1, n) {
        ke[2*i].pb(2*i-1);
        ke[2*i-1].pb(2*i);
    }

    fto(u, 1, 2*n) {
        if (!color[u]) DFS(u, 1);
    }

    forit(it, e) printf("%d %d\n", color[it->ff], color[it->ss]);

    return 0;
}