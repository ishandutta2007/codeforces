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
#define maxN 100005
#define oo 1000000000000000007LL

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, c[maxN];
string s[maxN];
ll f[2][maxN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &c[i]);
    fto(i, 1, n) cin >> s[i];

    f[1][1] = c[1];
    fto(i, 2, n) {
//        debug(i);
        fto(r2, 0, 1) {
//            debug(r2);
            f[r2][i] = oo;
            fto(r1, 0, 1) {
//                debug(r1);
                string s1 = s[i-1], s2 = s[i];
                if (r1) reverse(s1.begin(), s1.end());
                if (r2) reverse(s2.begin(), s2.end());
//                cout << s2 << " " << s1 << endl;
                if (s2 >= s1) {
                    f[r2][i] = min(f[r2][i], f[r1][i-1]+((r2 == 1) ? c[i] : 0));
//                    debug(f[r2][i]);
                }
            }
        }
    }

    ll ans = min(f[0][n], f[1][n]);
    cout << ((ans == oo) ? -1 : ans);


    return 0;
}