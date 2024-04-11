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
#define maxN 5005
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

string s;
int n, k;
bool dp[maxN][maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s;
    int n = s.length(), k = log2(n);

    dp[0][0] = true;
    fto(len, 0, n-(1<<k)) {
        fto(mask, 0, (1<<k)-1) {
            int i = len+mask;
            fto(j, 0, k-1)
                if (((mask>>j)&1) == 0) dp[i+(1<<j)][mask|(1<<j)] |= dp[i][mask];
        }
        char minC = 'z';
        fto(mask, 0, (1<<k)-1)
            if (dp[len+mask][mask]) minC = min(minC, s[len+mask]);
        fto(mask, 0, (1<<k)-1)
            if (s[len+mask] == minC) dp[len+mask+1][mask] |= dp[len+mask][mask];
        printf("%c", minC);
    }


    return 0;
}