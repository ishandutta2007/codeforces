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
#define maxN 205
#define maxK 1005
#define oo 3000000000000000000LL
#define MOD 1000000007

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

void add(ll &a, ll b) {a = (a+b)%MOD;}

int n, K, a[maxN];
ll f1[maxN][maxK], f2[maxN][maxK];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &K);
    fto(i, 1, n) scanf("%d", &a[i]);
    sort(a+1, a+n+1);

    f1[0][0] = 1;
    fto(i, 0, n-1) {
//        debug(i+1);
        fto(j, 0, n) {
            fto(k, 0, K) {
                if (f1[j][k] > 0) {
                    int val = k+(a[i+1]-a[i])*j; ll v = f1[j][k];
                    if (val <= K) {
                        if (j < n) add(f2[j+1][val], v);
                        add(f2[j][val], v);
                        add(f2[j][val], v*j);
                        if (j > 0) add(f2[j-1][val], v*j);
                    }
                }
            }
        }
        fto(j, 0, n) {
            fto(k, 0, K) f1[j][k] = f2[j][k], f2[j][k] = 0;
        }
//        fto(j, 0, n) {
//            fto(k, 0, K) printf("%d ", f1[j][k]);
//            puts("");
//        }
    }


    ll ans = 0;
    fto(k, 0, K) add(ans, f1[0][k]);
    cout << ans;

    return 0;
}