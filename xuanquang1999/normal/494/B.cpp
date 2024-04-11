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

void add(ll &a, ll b) {a = (a+b)%MOD;}

string s, t;
ll f[maxN], d[maxN], dd[maxN];
int z[maxN], l[maxN];

void buildZ(string s, int z[]) {
    int n = s.length(), l = 0, r = 0;
    z[0] = n;
    fto(i, 1, n-1) {
        if (i <= r) z[i] = min(z[i-l], r-i+1);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
        if (i+z[i]-1 > r) {l = i; r = i+z[i]-1;}
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s >> t;
    int nS = s.length(), nT = t.length();

    string w = t+"#"+s; int nW = w.length();
    buildZ(w, z);

    fto(i, 1, nS) {
        if (z[i+nT] == nT) l[i] = i;
        else l[i] = l[i-1];
    }

//    debug(w);
//    fto(i, 0, nW-1) printf("%d ", z[i]);
//    puts("");
//
//    fto(i, 1, nS) printf("%d ", l[i]);
//    puts("");

    f[0] = d[0] = dd[0] = 1;
    fto(i, 1, nS) {
        //debug(i);
        if (i >= nT) {
            int res = l[i-nT+1];
            add(f[i], dd[res-1]);

        }
        d[i] = (((i > 0) ? d[i-1] : 0) + f[i])%MOD;
        dd[i] = (((i > 0) ? dd[i-1] : 0) + d[i])%MOD;
    }

    ll ans = 0;
    fto(i, 1, nS) add(ans, f[i]);
//    fto(i, 0, nS) printf("%lld %lld %lld\n", f[i], d[i], dd[i]);
    printf("%d", ans);

    return 0;
}