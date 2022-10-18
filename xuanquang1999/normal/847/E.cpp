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
char s[maxN];
vector<int> pac, ask;

bool Check(int L) {
    int hi = 0;
    for(int p: pac) {
        int lo = hi;
        while (true) {
            if (hi == sz(ask)) return true;
            int t = min(abs(p-ask[lo])+abs(ask[lo]-ask[hi]), abs(p-ask[hi])+abs(ask[hi]-ask[lo]));
            if (t > L) break;
            ++hi;
        }
    }
    return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    scanf("%s", s);

    fto(i, 0, n-1) {
        if (s[i] == '*') ask.pb(i);
        else if (s[i] == 'P') pac.pb(i);
    }

    int lo = 1, hi = oo, res = 0;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (Check(mid)) {
            res = mid;
            hi = mid-1;
        } else lo = mid+1;
    }

    printf("%d", res);

    return 0;
}