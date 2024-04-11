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
#define MOD 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, f[maxN];
vector<int> d[maxN];
bool p[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    memset(p, true, sizeof p);
    fto(i, 2, sqrt(n+1)) {
        if (p[i]) {
            for(int j = i*i; j <= n+1; j += i) p[j] = false, d[j].pb(i);
        }
    }

    int maxC = 0;
    fto(i, 2, n+1) {
        vector<int> v;
        forit(it, d[i]) v.pb(f[*it]);
        sort(v.begin(), v.end());
//        debug(i);
//        forit(it, v) printf("%d ", *it);
//        puts("");
        fto(c, 0, v.size()) {
            if (c == v.size() || v[c] != c+1) {f[i] = c+1; maxC = max(maxC, c+1); break;}
        }
    }

    printf("%d\n", maxC);
    fto(i, 2, n+1) printf("%d ", f[i]);



    return 0;
}