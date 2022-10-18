//84104971101048411497 - Can you guess what does this mean?
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

int n;
bool pr[maxN], chosen[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 2, n) pr[i] = true;
    for(int i = 2; i*i <= n; ++i) {
        if (pr[i]) {
            for(int j = i*i; j <= n; j += i) pr[j] = false;
        }
    }

    vector<ii> ans;
    fdto(i, n/2, 2) {
        if (pr[i]) {
            vector<int> v;
            for(int j = i; j <= n; j += i) {
                if (!chosen[j]) v.pb(j);
            }
            if (sz(v)&1) v.erase(find(v.begin(), v.end(), 2*i));

            fto(i, 0, sz(v)/2-1) {
                ans.pb(mp(v[2*i], v[2*i+1]));
                chosen[v[2*i]] = chosen[v[2*i+1]] = true;
            }
        }
    }

    printf("%d\n", sz(ans));
    forit(it, ans) printf("%d %d\n", it->ff, it->ss);

    return 0;
}