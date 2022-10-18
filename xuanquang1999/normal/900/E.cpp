//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
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
#define maxN 100005
#define oo 1000000007
#define MOD 1000000007
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

int n, m, z[maxN], cost[maxN];
ii dp[maxN], maxDP[maxN];
bool ok[maxN];
string s;

ii getMax(const ii &a, const ii &b) {
    return (a.ff > b.ff || (a.ff == b.ff && a.ss < b.ss)) ? a : b;
}

ii combine(const ii &a, int x) {
    return mp(a.ff+1, a.ss+x);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    cin >> s;
    scanf("%d", &m);

    fto(i, 0, n-1) {
        cost[i] = (s[i] == '?');
        if (i > 0) cost[i] += cost[i-1];
        if (i >= m) cost[i] -= (s[i-m] == '?');
    }

    for(int i = 1; i < n; i += 2) {
        if (s[i] != '?') s[i] = 'a'+'b'-s[i];
    }
    fto(r, 0, 1) {
        fdto(i, n-1, 0)
            z[i] = (s[i] == 'a'+r || s[i] == '?') ? z[i+1]+1 : 0;
        for(int i = r; i <= n-m; i += 2)
            ok[i+m-1] = (z[i] >= m);
    }

//    fto(i, 0, n-1) printf("%d %d\n", cost[i], ok[i]);

    fto(i, 0, n-1) {
        if (ok[i])
            dp[i] = combine((i >= m) ? maxDP[i-m] : mp(0, 0), cost[i]);
        else dp[i] = mp(-oo, oo);

        maxDP[i] = getMax((i == 0) ? mp(0, 0) : maxDP[i-1], dp[i]);

//        printf("(%d, %d) (%d, %d)\n", dp[i].ff, dp[i].ss, maxDP[i].ff, maxDP[i].ss);
    }

    printf("%d", maxDP[n-1].ss);

    return 0;
}