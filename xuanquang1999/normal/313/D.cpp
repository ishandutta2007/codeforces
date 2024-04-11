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
#define maxN 305
#define oo 1000000000000000007LL
#define sz(a) int(a.size())

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

int n, m, k;
vector<ii> v[maxN];
ll f[maxN][maxN];
vector<ll> minF[2*maxN], fV[2*maxN];

ll minimize(ll &a, ll b) {a = min(a, b);}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 1, m) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        v[r].pb(mp(l, c));
    }

    fto(r, 0, n) {
        fto(i, 0, n) {
//            printf("%d %d\n", r, i);
            int x = r-i+n;

            if (r == 0) f[r][i] = ((i == 0) ? 0 : oo);
            else {
                f[r][i] = f[r-1][i];
                forit(it, v[r]) {
                    int l = it->ff, c = it->ss;
                    if (minF[x].size() > 0) minimize(f[r][i], minF[x][min(i-1, r-l)]+c);
                }
            }

            fV[x].pb(f[r][i]);
            fto(j, 0, sz(minF[x])-1) minimize(minF[x][j], f[r][i]);
            minF[x].insert(minF[x].begin(), f[r][i]);
        }
    }

//    fto(r, 0, n) {
//        fto(i, 0, n) printf("%lld ", f[r][i]);
//        puts("");
//    }

    ll ans = oo;
    fto(i, k, n) minimize(ans, f[n][i]);
    if (ans == oo) puts("-1");
    else printf("%lld", ans);

    return 0;
}