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
#define maxN 25
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, a[maxN][maxN];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) fto(j, 1, m) scanf("%d", &a[i][j]);

    fto(j1, 1, m) {
        fto(j2, j1, m) {
            fto(i, 1, n) swap(a[i][j1], a[i][j2]);
//
//            fto(i, 1, n) {
//                fto(j, 1, m) printf("%d ", a[i][j]);
//                puts("");
//            }
//            puts("");

            bool res = true;
            fto(i, 1, n) {
                bool ok = false;
                fto(j3, 1, m) {
                    fto(j4, j3, m) {
                        swap(a[i][j3], a[i][j4]);
                        bool inc = true;
                        fto(j, 1, m-1) {
                            if (a[i][j] > a[i][j+1]) {inc = false;}
                        }
                        if (inc) ok = true;
                        swap(a[i][j3], a[i][j4]);
                    }
                }
                if (!ok) res = false;
            }
            if (res) {puts("YES"); return 0;}

            fto(i, 1, n) swap(a[i][j1], a[i][j2]);
        }
    }

    puts("NO");

    return 0;
}