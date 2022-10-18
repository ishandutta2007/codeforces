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
#define maxN 5005
#define oo 2000000007
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

int n, m, f[maxN][maxN];
char s[maxN][maxN];

bool isPrime(int x) {
    int lim = sqrt(x);
    fto(i, 2, lim) {
        if (x&i == 0) return false;
    }
    return true;
}

int Calc(int x1, int y1, int x2, int y2) {
    return f[x2][y2]-f[x1-1][y2]-f[x2][y1-1]+f[x1-1][y1-1];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, n-1) {
        scanf("%s", s[i]);
        fto(j, 0, m-1) f[i+1][j+1] = s[i][j]-'0';
    }

    fto(i, 1, max(m, n)*2) fto(j, 1, max(m, n)*2) f[i][j] += f[i-1][j]+f[i][j-1]-f[i-1][j-1];

//    fto(i, 1, n) {
//        fto(j, 1, m) printf("%d ", f[i][j]);
//        puts("");
//    }

    int ans = oo;
    fto(k, 2, max(n, m)) {
        if (isPrime(k)) {
            int sum = 0;
            for(int x = 1; x <= n; x += k) {
                for(int y = 1; y <= m; y += k) {
                    int d = Calc(x, y, x+k-1, y+k-1);
                    sum += min(d, k*k-d);
                }
            }
            ans = min(ans, sum);
        }
    }

    printf("%d", ans);

    return 0;
}