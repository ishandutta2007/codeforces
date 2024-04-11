#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
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

const int MAXN = 100005;

int n, k, A, B;
vector<int> a;

int countAvenger(int l, int r) {
    return upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
}

ll solve(int lo, int hi) {
    int cnt = countAvenger(lo, hi);
    if (cnt == 0)
        return A;

    ll res = 1LL * B * cnt * (hi-lo+1);
    if (lo < hi) {
        int mid = (lo + hi)/2;
        res = min(res, solve(lo, mid) + solve(mid+1, hi));
    }

    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d", &n, &k, &A, &B);
    a.resize(k);
    fto(i, 0, k-1) {
        scanf("%d", &a[i]);
        --a[i];
    }

    sort(a.begin(), a.end());

    printf("%lld", solve(0, (1<<n)-1));

    return 0;
}