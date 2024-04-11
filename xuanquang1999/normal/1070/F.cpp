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

const int MAXN = 400005;

int n;
vector<int> a[4];

void revSort(vector<int> &a) {
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        char s[3]; int x;
        scanf("%s%d", s, &x);
        int type = 2*(s[0]-'0') + (s[1]-'0');
        a[type].pb(x);
    }

    fto(type, 0, 3)
        revSort(a[type]);

    while (sz(a[2]) < sz(a[1])) {
        a[0].pb(a[1].back());
        a[1].pop_back();
    }
    while (sz(a[1]) < sz(a[2])) {
        a[0].pb(a[2].back());
        a[2].pop_back();
    }
    revSort(a[0]);

    ll sum = 0, ans = 0;
    for(int x: a[3])
        sum += x;
    for(int x: a[0])
        sum += x;

//    fto(type, 0, 3) {
//        for(int x: a[type]) printf("%d ", x);
//        puts("");
//    }

    int j = sz(a[0])-1;
    fto(i, 0, sz(a[1])) {
        int sup = sz(a[3]) + i, tot = sz(a[3]) + 2*i;
        int x = 2*sup - tot;
        if (x < 0) break;

        while (j >= x) {
            sum -= a[0][j];
            --j;
        }

        ans = max(ans, sum);

        if (i < sz(a[1]))
            sum += a[1][i] + a[2][i];
    }

    printf("%lld", ans);

    return 0;
}