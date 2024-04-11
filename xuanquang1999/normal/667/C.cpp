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
#define maxN 10005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

string s;
int n, f[4][maxN];
set<string> ss;

int Solve(int u, int i) {
    if (i+u == n) return 1;
    if (i+u > n) return 0;
    if (f[u][i] != -1) return f[u][i];
    bool res = false;
//    printf("%d %d\n", u, i);
    fto(v, 2, 3) {
        if (s.substr(i, u) != s.substr(i+u, v)) res |= Solve(v, i+u);
    }
    return (f[u][i] = res);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s; n = s.length();
    fto(v, 2, 3) {
        fto(i, 0, n-1) f[v][i] = -1;
    }

    fto(v, 2, 3) {
        fto(i, 5, n-1) {
            if (Solve(v, i)) ss.insert(s.substr(i, v));
        }
    }

    printf("%d\n", ss.size());
    forit(it, ss) cout << *it << endl;


    return 0;
}