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
#define maxN 2005
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

ll mul(ll a, ll b) {
    if (a*b/a != b) return oo;
    return min(oo, a*b);
}

int n, m, k;
bool dp[maxN];
vector<int> d;
unordered_map<int, int> ind;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    if (n%2 == 0) puts("Marsel");
    else {
        fto(i, 1, sqrt(m)) {
            if (m%i == 0) {
                d.pb(i);
                if (i*i != m) d.pb(m/i);
            }
        }
        sort(d.begin(), d.end());

        fto(i, 0, sz(d)-1) ind[d[i]] = i;

        fto(i, 0, sz(d)-1) {
            fto(j, 0, i-1) {
                if (d[j] >= k) {
                    if (d[i]/d[j] % 2 == 0) {
                        dp[i] = true;
                        break;
                    } else dp[i] |= !dp[j];
                }
            }
        }

        puts((dp[sz(d)-1]) ? "Timur" : "Marsel");
    }

    return 0;
}