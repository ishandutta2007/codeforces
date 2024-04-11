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
#define maxN 1000005
#define MOD 1000000007

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

struct meeting {
    int s, f, id;
    bool inline operator < (const meeting &o) const {
        return s < o.s;
    }
};

int n, m, cnt[maxN], fact[maxN];
vector<ii> v[maxN];
map<vector<ii>, int> ma;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        int k; scanf("%d", &k);
        vector<int> save;
        fto(j, 1, k) {
            int x; scanf("%d", &x);
            if (cnt[x] == 0) save.pb(x);
            ++cnt[x];
        }
        forit(it, save) v[*it].pb(mp(i, cnt[*it])), cnt[*it] = 0;
    }
//    fto(i, 1, m) {
//        debug(i);
//        forit(it, v[i]) printf("%d %d\n", it->ff, it->ss);
//        puts("");
//    }

    fact[0] = 1;
    fto(i, 1, m) {
        fact[i] = ((ll)fact[i-1]*i)%MOD;
        ++ma[v[i]];
    }

    int ans = 1;
    forit(it, ma) ans = ((ll)ans*fact[it->ss])%MOD;
    printf("%d", ans);





    return 0;
}