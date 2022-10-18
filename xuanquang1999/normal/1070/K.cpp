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

int n, k, a[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    int sum = 0;
    fto(i, 1, n) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    if (sum%k != 0) {
        puts("No");
        return 0;
    }
    sum /= k;

    vector<int> ans;
    int cur = 0, last = 0;
    fto(i, 1, n) {
        cur += a[i];
        if (cur > sum) {
            puts("No");
            return 0;
        }
        if (cur == sum) {
            ans.pb(i-last);
            last = i;
            cur = 0;
        }
    }

    puts("Yes");
    for(int x: ans)
        printf("%d ", x);

    return 0;
}