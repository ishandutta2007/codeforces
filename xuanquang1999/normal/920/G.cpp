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
#define maxN 300005
#define maxX 1000005
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

int nxt[maxX], nTest;
vector<int> prime;

int Count(vector<int> &d, const int &mid) {
    ll cnt = 0;
    fto(i, 0, (1<<sz(d))-1) {
        int prod = 1, sign = 1;
        fto(j, 0, sz(d)-1) {
            if ((i>>j)&1) {
                prod *= d[j];
                sign *= -1;
            }
        }
        cnt += (mid/prod)*sign;
    }
    return cnt;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fto(i, 2, maxX-1) {
        if (nxt[i] == 0) {
            nxt[i] = i;
            prime.pb(i);
        }
        for(int j = 0; prime[j] <= (maxX-1)/i; ++j) {
            nxt[prime[j]*i] = prime[j];
            if (i%prime[j] == 0) break;
        }
    }

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        int x, p, k;
        scanf("%d%d%d", &x, &p, &k);

        vector<int> d;
        while (p > 1) {
            int k = nxt[p];
            while (nxt[p] == k) p /= k;
            d.pb(k);
        }

        int cntX = Count(d, x);

        int lo = x+1, hi = 1000000000, res;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (Count(d, mid)-cntX >= k) {
                res = mid;
                hi = mid-1;
            } else lo = mid+1;
        }

        printf("%d\n", res);
    }

    return 0;
}