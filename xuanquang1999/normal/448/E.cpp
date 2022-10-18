#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
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
#define X real()
#define Y imag()
#define maxN 100005
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

vector<ll> ans;
map<ll, vector<ll> > md;

void DFS(ll n, ll k) {
    if (sz(ans) == 100000) return;
    if (n == 1 || k == 0) {ans.pb(n); return;}

    vector<ll> d;
    if (!md.count(n)) {
        fto(i, 1, sqrtl(n)) {
            if (n%i == 0) {
                d.pb(i);
                if (1LL*i*i != n) d.pb(n/i);
            }
        }
        sort(d.begin(), d.end());
        md[n] = d;
    } else d = md[n];

    forit(it, d) DFS(*it, k-1);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ll n, k;
    cin >> n >> k;
    DFS(n, k);

    forit(it, ans) printf("%lld ", *it);

    return 0;
}