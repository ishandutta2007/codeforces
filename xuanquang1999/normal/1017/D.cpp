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
#define maxN 12
#define maxK 100
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

int n, m, q, w[maxN], cnt[1<<maxN], ans[1<<maxN][maxK+1];

int strToBin(char s[]) {
    int x = 0;
    fto(i, 0, n-1)
        if (s[i]-'0') x |= 1<<i;
    return x;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &q);
    fto(i, 0, n-1) scanf("%d", &w[i]);

    fto(i, 1, m) {
        char s[maxN+1]; scanf("%s", s);
        ++cnt[strToBin(s)];
    }

//    fto(i, 0, (1<<n)-1)
//        printf("%d ", cnt[i]);
//    puts("");

    fto(x, 0, (1<<n)-1) {
        fto(y, 0, (1<<n)-1) {
            int sum = 0;
            fto(i, 0, n-1)
                if (((x>>i)&1) == ((y>>i)&1)) sum += w[i];
            if (sum <= maxK) ans[x][sum] += cnt[y];
//            printf("%d %d %d\n", x, y, sum);
        }
        fto(k, 1, maxK)
            ans[x][k] += ans[x][k-1];
    }

    fto(i, 1, q) {
        char s[maxN+1]; scanf("%s", s);
        int x = strToBin(s), k;
        scanf("%d", &k);
        printf("%d\n", ans[x][k]);
    }



    return 0;
}