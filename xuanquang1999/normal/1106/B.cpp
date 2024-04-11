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

int n, m, a[MAXN], c[MAXN];
pii ord[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, n) scanf("%d", &c[i]);

    fto(i, 1, n)
        ord[i] = {c[i], i};
    sort(ord+1, ord+n+1);

    int j = 1;
    fto(i, 1, m) {
        int t, d;
        scanf("%d%d", &t, &d);

        ll res = 0;

        int x = min(a[t], d);
        a[t] -= x; d -= x;
        res += 1LL*x*c[t];

        while (j <= n && d > 0) {
            int id = ord[j].second;

            x = min(a[id], d);
            a[id] -= x; d -= x;
            res += 1LL*x*c[id];

            if (d == 0)
                break;
            ++j;
        }

        if (d > 0)
            res = 0;

//        fto(i, 1, n) printf("%d ", a[i]);
//        puts("");
        printf("%lld\n", res);
    }


    return 0;
}