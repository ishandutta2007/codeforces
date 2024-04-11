//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 2005
#define MOD 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int m, d, n, f[maxN][maxN][2];
string a, b;

int DP(string &s, int i, int r, bool low) {
    if (i == n) return (r == 0);
    if (f[i][r][low] != -1) return f[i][r][low];

    int res = 0, a = (i == 0) ? 1 : 0, b = (low) ? 9 : (s[i]-'0');
    if (i%2 == 1) a = max(a, d), b = min(b, d);
    fto(x, a, b) {
        if (i%2 == 1 || x != d) res = (res + DP(s, i+1, (r*10+x)%m, (low)|(x < s[i]-'0')))%MOD;
    }

    return (f[i][r][low] = res);
}

int Solve(string &s) {
    fto(i, 0, n-1)
        fto(r, 0, m-1)
            fto(low, 0, 1) f[i][r][low] = -1;
    return DP(s, 0, 0, 0);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &m, &d);
    cin >> a >> b;
    n = a.length();

    int mem = 1;
    fdto(i, n-1, 0) {
        a[i] -= mem;
        if (a[i] < '0') {
            a[i] += 10;
            mem = 1;
        }
        else mem = 0;
    }
//    debug(Solve(b));
//    debug(Solve(a));
    if (a[0] == 0) cout << Solve(b);
    else cout << (Solve(b)-Solve(a)+MOD)%MOD;

    return 0;
}