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

const int MAXN = 1000005;
int x[MAXN], n;
char s[MAXN];
map<int, int> m;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    ll ans = 0;
    fto(i, 1, n) {
        scanf("%s", s);

        int mask = 0, k = strlen(s);
        fto(i, 0, k-1) {
            int c = s[i] - 'a';
            mask ^= (1<<c);
        }

        ans += m[mask];
        fto(c, 0, 25) {
            ans += m[mask^(1<<c)];
        }

        ++m[mask];
    }

    printf("%lld\n", ans);

    return 0;
}