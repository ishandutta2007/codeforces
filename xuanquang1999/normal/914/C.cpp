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
#define maxN 1005
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

void add(int &a, int b) {a = (a+b)%MOD;}

string s;
int k, op[maxN], dp[maxN][maxN][2];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    op[1] = 0;
    fto(i, 2, maxN-1) op[i] = op[__builtin_popcount(i)]+1;

    cin >> s >> k;
    if (k == 0) {
        puts("1");
        return 0;
    }

    fto(d, 0, 1) dp[0][d][d < s[0]-'0'] = 1;
    fto(i, 0, sz(s)-2) {
        fto(j, 0, i+1) {
            fto(lo, 0, 1) {
                int lim = (lo) ? 1 : (s[i+1]-'0');
                fto(d, 0, lim) add(dp[i+1][j+d][lo|(d < s[i+1]-'0')], dp[i][j][lo]);
            }
        }
    }

//    fto(i, 0, sz(s)-1) fto(j, 0, 3) printf("%d")

    int ans = 0;
    fto(j, 1, maxN-1)
        if (op[j] == k-1) add(ans, (dp[sz(s)-1][j][0]+dp[sz(s)-1][j][1])%MOD);

    if (k == 1) add(ans, MOD-1);
    printf("%d", ans);



    return 0;
}