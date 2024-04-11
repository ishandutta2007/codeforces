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

int n, a[MAXN], f[MAXN], cntF[MAXN], tot, maxF;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int ans = -1;

    for(int i = 0; i < n; ++i) {
        int x = a[i];

        if (!f[x])
            ++tot;
        --cntF[f[x]];
        ++f[x];
        ++cntF[f[x]];

        maxF = max(maxF, f[x]);

        if (maxF == 1 || (cntF[maxF] == 1 && cntF[maxF-1] == tot-1) || (cntF[1] == 1 && cntF[maxF] == tot-1))
            ans = i+1;
    }

    printf("%d", ans);

    return 0;
}