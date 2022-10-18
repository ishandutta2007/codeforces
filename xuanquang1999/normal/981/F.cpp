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
#define maxN 200005
#define MOD 998244353
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

int n, L;
ll a[4*maxN], b[4*maxN];

bool Check(int x) {
    int j;
    vector<int> fl(2*n), fr(2*n);

    j = 0;
    fto(i, n, 3*n-1) {
        while (j < 3*n && a[i]-b[j] > x) ++j;
        fl[i-n] = j-i;
    }

    j = 4*n-1;
    fdto(i, 3*n-1, n) {
        while (j >= 0 && b[j]-a[i] > x) --j;
        fr[i-n] = i-j;
    }

    deque<int> q;
    fto(i, 0, 2*n-1) {
        while (!q.empty() && fl[q.back()] <= fl[i]) q.pop_back();
        q.push_back(i);
        while (q.front() <= i-n) q.pop_front();
        if (fl[q.front()]+fr[i] > 0) return false;
    }

    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &L);
    fto(i, 0, n-1) scanf("%d", &a[i]);
    fto(i, 0, n-1) scanf("%d", &b[i]);
    sort(a, a+n);
    sort(b, b+n);

    fto(i, n, 4*n-1) {
        a[i] = a[i-n]+L;
        b[i] = b[i-n]+L;
    }

    int lo = 0, hi = L/2, res = 0;
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