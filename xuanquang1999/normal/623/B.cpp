//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
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
#define ll long long
#define maxN 1000005
#define maxK 20
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

int n, a, b, x[maxN];
ll ans = (ll)oo*oo, f[maxN][3];

bool isPrime(int n) {
    if (n < 2) return false;
    int lim = sqrt(n);
    fto(i, 2, lim) {
        if (n%i == 0) return false;
    }
    return true;
}

void Solve (int p) {
    if (!isPrime(p)) return;
    fto(i, 0, n) {
        fto(k, 0, 2) f[i][k] = (ll)oo*oo;
    }
    f[0][0] = 0;
    fto(i, 1, n) {
        if (x[i]%p == 0) {
            f[i][0] = f[i-1][0];
            f[i][2] = min(f[i-1][1], f[i-1][2]);
        }
        else if ((x[i]-1)%p == 0 || (x[i]+1)%p == 0) {
            f[i][0] = f[i-1][0] + b;
            f[i][2] = min(f[i-1][1], f[i-1][2]) + b;
        }
        f[i][1] = min(f[i-1][0], f[i-1][1]) + a;
    }
    fto(k, 0, 2) ans = min(ans, f[n][k]);
}

void Try(int p) {
    int lim = sqrt(p);
    fto(i, 1, lim) {
        if (p%i == 0) {
            Solve(i);
            Solve(p/i);
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &a, &b);
    fto(i, 1, n) scanf("%d", &x[i]);

    fto(d, -1, 1) {
        Try(x[1]+d);
        Try(x[n]+d);
    }

    cout << ans;

    return 0;
}