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
#define maxN 100005
#define oo 1000000007
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

int n, minA, maxA;
map<int, int> m;

void erase(int x, int cnt) {
    if (m[x] < cnt) {
        puts("NO");
        exit(0);
    }
    m[x] -= cnt;
    if (m[x] == 0) m.erase(x);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    if (n%2 == 1) {
        puts("NO");
        return 0;
    }

    minA = oo; maxA = 0;
    fto(i, 1, n) {
        int x; scanf("%d", &x);
        minA = min(minA, x);
        maxA = max(maxA, x);
        ++m[x];
    }

    ++m[maxA];
    fdto(x, maxA, minA+1) erase(x, 1);

    int last = minA+1;
    while (m.size() > 0) {
        int x = m.begin()->ff, cnt = m.begin()->ss;
        if (abs(last-x) != 1) {
            puts("NO");
            exit(0);
        }
        erase(x, cnt);
        erase(x+1, cnt-1);
        last = x;
    }

    puts("YES");

    return 0;
}