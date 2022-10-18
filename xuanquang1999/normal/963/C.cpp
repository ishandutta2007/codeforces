//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cerr << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cerr << a[i] << " "; cout << endl
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
#define maxN 200005
#define oo 1000000000000000007LL
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

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a%b);}

int n;
map<ll, vector<pair<ll, ll> > > m;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        ll w, h, c;
        scanf("%lld%lld%lld", &w, &h, &c);
        m[w].pb(mp(h, c));
    }

    ll allRowGCD = 0;
    vector<pair<ll, ll> > sample;
    forit(it, m) {
        vector<pair<ll, ll> > row = it->ss;
        sort(row.begin(), row.end());

        ll rowGCD = 0;
        fto(i, 0, sz(row)-1) rowGCD = gcd(rowGCD, row[i].ss);
        fto(i, 0, sz(row)-1) row[i].ss /= rowGCD;

        allRowGCD = gcd(allRowGCD, rowGCD);

        if (sample.empty()) sample = row;
        else if (sample != row) {
            puts("0");
            return 0;
        }
    }

    int ans = 0;
    for(long long i = 1; i*i <= allRowGCD; ++i) {
        if (allRowGCD%i == 0) {
            ++ans;
            if (i*i < allRowGCD) ++ans;
        }
    }

    printf("%d", ans);

    return 0;
}