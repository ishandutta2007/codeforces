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
#define maxX 75
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

void add(ll &a, ll b) {a = (a+b)%MOD;}

int prime[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int n, a[maxX], cnt[maxX];
ll e2[maxN], dp[2][1<<19];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        int x; scanf("%d", &x);
        ++cnt[x];
    }

    fto(i, 1, 70) {
        int x = i;
        fto(j, 0, 18) {
            int cnt = 0;
            while (x%prime[j] == 0) {
                ++cnt;
                x /= prime[j];
            }
            if (cnt&1) a[i] |= 1<<j;
        }
    }

    e2[0] = 1;
    fto(i, 1, n) e2[i] = (e2[i-1]*2)%MOD;

    dp[0][0] = 1;
    fto(i, 1, 70) {
        if (cnt[i] > 0) {
            fto(mask, 0, (1<<19)-1) {
                add(dp[1][mask], dp[0][mask]*e2[cnt[i]-1]);
                add(dp[1][mask^a[i]], dp[0][mask]*e2[cnt[i]-1]);
            }
            fto(mask, 0, (1<<19)-1) dp[0][mask] = dp[1][mask], dp[1][mask] = 0;
        }
    }

    printf("%lld\n", (dp[0][0]+MOD-1)%MOD);

    return 0;
}