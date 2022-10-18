//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
#define maxN 300005
#define BASE 300
#define oo 2000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct query {int a, id;};

int n, q, w[maxN];
vector<ll> sum[BASE];
vector<query> Q[BASE+1];
ll ans[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &w[i]);

    scanf("%d", &q);
    fto(iq, 1, q) {
        int a, b;
        scanf("%d%d", &a, &b); --a;
        if (b <= BASE) Q[b].pb({a, iq});
        else {
            for(int i = a; i < n; i += b) ans[iq] += w[i];
        }
    }

    fto(b, 1, BASE) {
        fto(r, 0, b-1) sum[r].clear();
        fto(i, 0, n-1) sum[i%b].pb(w[i]);
        fto(r, 0, b-1) {
            fdto(i, sz(sum[r])-2, 0) sum[r][i] += sum[r][i+1];
        }
        for(query q: Q[b]) ans[q.id] = sum[q.a%b][q.a/b];
    }

    fto(i, 1, q) printf("%lld\n", ans[i]);

    return 0;
}