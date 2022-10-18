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
#define maxN 300000000
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

bitset<maxN+1> bs;


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    vector<int> prime(16252325);
    int n = 0;
    bs[1] = true;
    for(int i = 2; i <= maxN; ++i) {
        if (!bs[i]) prime[n++] = i;
        int x = maxN/i;
        for(int j = 0; prime[j] <= x; ++j) {
            bs[i*prime[j]] = true;
            if (i%prime[j] == 0) break;
        }
    }
    
    int l, r, cnt = 0;
    scanf("%d%d", &l, &r);

    for(int i = (l+2)/4*4+1; i <= r; i += 4)
        if (!bs[i]) ++cnt;
    if (l <= 2 && 2 <= r) ++cnt;
    printf("%d", cnt);
    
    return 0;
}