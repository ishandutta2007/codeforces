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
#define y1 ipanhefioaenf

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

const int MAXN = 10005;

int n, p[MAXN];
char s[3][MAXN], resp[3][MAXN], t[MAXN], ans[MAXN];


int main () {
    scanf("%s", t);
    n = strlen(t);

    fto(i, 0, n-1) {
        int x = i;
        fto(j, 0, 2) {
            s[j][i] = 'a' + x%26;
            x /= 26;
        }
    }
    fto(j, 0, 2)
        s[j][n] = 0;

    fto(i, 0, 2) {
        printf("? %s\n", s[i]);
        fflush(stdout);

        scanf("%s", resp[i]);
    }

    fto(i, 0, n-1) {
        int dest = 0;
        fdto(j, 2, 0) {
            dest = 26 * dest + resp[j][i] - 'a';
        }
        p[i] = dest;
    }

    fto(i, 0, n-1)
        ans[p[i]] = t[i];
    ans[n] = 0;

    printf("! %s", ans);
    fflush(stdout);

    return 0;
}