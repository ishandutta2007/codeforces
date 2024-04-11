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

const int MAXN = 105;

int n, s[MAXN];
char ans[MAXN];
vector<int> pos[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &s[i]);
        pos[s[i]].pb(i);
    }

    int niceA = 0, niceB = 0;
    fto(x, 1, MAXN-1) {
        if (sz(pos[x]) == 1) {
            if (niceA < niceB) {
                ans[pos[x][0]] = 'A';
                ++niceA;
            } else {
                ans[pos[x][0]] = 'B';
                ++niceB;
            }
        }
        if (sz(pos[x]) == 2) {
            for(int i: pos[x]) ans[i] = 'A';
        }
    }

    fto(x, 1, MAXN-1) {
        if (sz(pos[x]) > 2) {
            if (niceA < niceB) {
                ans[pos[x][0]] = 'A';
                ++niceA;
            } else
                ans[pos[x][0]] = 'B';

            fto(i, 1, sz(pos[x])-1)
                ans[pos[x][i]] = 'B';
        }
    }

    if (niceA == niceB) {
        puts("YES");
        fto(i, 1, n) printf("%c", ans[i]);
    } else
        puts("NO");

    return 0;
}