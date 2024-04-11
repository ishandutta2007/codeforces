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
#define MOD 1000
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

int n, num[maxN];
bool asked[maxN];

int get(int i) {
    i %= n;
    ++i;
    if (!asked[i]) {
        asked[i] = true;
        printf("? %d\n", i);

        fflush(stdout);
        scanf("%d", &num[i]);

        asked[i] = true;
    }
    return num[i];
}

void answer(int x) {
    if (x == -1)
        x = -2;
    printf("! %d\n", x+1);
    fflush(stdout);
    exit(0);
}

int Solve(int l1, int r1, int l2, int r2) {
    int lo = 1, hi = r1-l1-1;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        ll x = 1LL*(get(l1+mid)-get(l2+mid))*(get(l1)-get(l2));
        if (x < 0) {
            hi = mid-1;
        } else if (x > 0) {
            lo = mid+1;
        } else
            return l1+mid;
    }
    return -1;
}

int main () {
    scanf("%d", &n);

    int ans = -1;
    if ((n/2)%2 == 1)
        answer(ans);

    vector<int> pos = {0, n/4, n/2, 3*n/4};
    for(int i = 0; i < 4; ++i) {
        int a = pos[i], b = pos[(i+1)%4], c = pos[(i+2)%4], d = pos[(i+3)%4];
        if (get(a) == get(c))
            answer(a);
        if (get(b) == get(d))
            answer(b);

        if (1LL*(get(a)-get(c))*(get(b)-get(d)) < 0) {
            ans = Solve(a, b, c, d);
            break;
        }
    }

    answer(ans%n);

    return 0;
}