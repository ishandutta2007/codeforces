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
#define maxN 100005
#define maxK 20
#define oo 1000000000000000007LL

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

int n, a[3][maxN];
ll f[3][maxN];

ll sumC(int j, int i1, int i2) {
    if (i1 > i2) swap(i1, i2);
    ll res = 0;
    fto(i, i1, i2) res += a[i][j];
    return res;
}

void maximize(ll &a, ll b) {a = max(a, b);}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, 2) fto(j, 1, n) scanf("%d", &a[i][j]);

    f[1][0] = f[2][0] = -oo;
    fto(j, 1, n) {
        fto(i, 0, 2) {
            f[i][j] = -oo;
            fto(k, 0, 2) {
                maximize(f[i][j], f[k][j-1]+sumC(j, i, k));
            }
        }

        if (j > 1) {
            ll sumLeft = sumC(j, 0, 2)+sumC(j-1, 0, 2);
            maximize(f[0][j], f[2][j-2]+sumLeft);
            maximize(f[2][j], f[0][j-2]+sumLeft);
        }
    }

    cout << f[2][n];

    return 0;
}