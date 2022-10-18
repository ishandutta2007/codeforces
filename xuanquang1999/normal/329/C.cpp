//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
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
#define maxN 100005
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, ans[maxN];
vector<int> ke[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v; scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }
    fto(u, 1, n) sort(ke[u].begin(), ke[u].end());

    fto(u, 0, n-1) ans[u] = u+1;

    fto(t, 1, 100) {
        random_shuffle(ans, ans+n);
        bool good = true;
        fto(i, 0, m-1) {
            if (binary_search(ke[ans[i]].begin(), ke[ans[i]].end(), ans[(i+1)%n])) {
                good = false;
                break;
            }
        }
        if (good) {
            fto(i, 0, m-1) printf("%d %d\n", ans[i], ans[(i+1)%n]);
            return 0;
        }
    }

    puts("-1");

    return 0;
}