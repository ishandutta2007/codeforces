#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
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

const int MAXN = 100005;
const int MAXM = 205;
const ll oo = 1000000000000000007LL;

struct Envelope {
    int w, d, id;
    bool inline operator < (const Envelope &rhs) const {
        return make_tuple(w, d, id) > make_tuple(rhs.w, rhs.d, rhs.id);
    }
};

int n, m, k, s[MAXN], t[MAXN], d[MAXN], w[MAXN], bestID[MAXN];
vector<int> toAdd[MAXN], toRemove[MAXN];
ll dp[MAXN][MAXM];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 1, k) {
        scanf("%d%d%d%d", &s[i], &t[i], &d[i], &w[i]);
        toAdd[s[i]].pb(i);
        toRemove[t[i]+1].pb(i);
    }

    set<Envelope> envSet;
    fto(i, 1, n) {
        for(int id: toAdd[i])
            envSet.insert({w[id], d[id], id});
        for(int id: toRemove[i])
            envSet.erase({w[id], d[id], id});

        if (envSet.empty())
            bestID[i] = -1;
        else
            bestID[i] = envSet.begin()->id;
    }

    fto(i, 0, n)
        fto(j, 0, m) dp[i][j] = oo;

    dp[0][0] = 0;
    fto(i, 1, n) {
        fto(j, 0, m) {
            if (j > 0)
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);

            int id = bestID[i];
            if (id == -1)
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            else
                dp[d[id]][j] = min(dp[d[id]][j], dp[i-1][j] + w[id]);
        }
    }

    ll ans = oo;
    fto(j, 0, m)
        ans = min(ans, dp[n][j]);

    printf("%lld", ans);

    return 0;
}