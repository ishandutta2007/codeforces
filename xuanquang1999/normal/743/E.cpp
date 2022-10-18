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
#define maxN 1005
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

void maximize(int &a, int b) {a = max(a, b);}

int n, cnt[8], a[maxN], r[8][maxN][maxN], f[maxN][256];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]), --a[i], ++cnt[a[i]];

    int avail = 0;
    fto(d, 0, 7) avail += (cnt[d] > 0);
    if (avail != 8) {printf("%d", avail); return 0;}

    fto(d, 0, 7) {
        fto(i, 1, n) {
            int cnt = 0;
            r[d][i][0] = i;
            fto(j, i, n) {
                if (a[j] == d) {
                    ++cnt;
                    r[d][i][cnt] = j;
                }
            }
            fto(j, cnt+1, n) r[d][i][j] = n+1;
        }
    }
//    fto(i, 1, n) {
//        fto(cnt, 1, n) printf("%d ", r[0][i][cnt]);
//        puts("");
//    }

    int ans = 0;
    fto(cnt, 0, n/8) {
//        debug(cnt);
        fto(i, 0, n) {
            fto(b, 0, 255) f[i][b] = -oo;
        }
        f[0][0] = 0;
        fto(i, 0, n-1) {
            fto(b, 0, 255) {
                maximize(f[i+1][b], f[i][b]);
                if (!(b&(1<<a[i+1]))) {
                    fto(k, 0, 1) {
                        int I = r[a[i+1]][i+1][cnt+k], B = b|(1<<a[i+1]);
                        maximize(f[I][B], f[i][b]+cnt+k);
                    }
                }
            }
        }
        fto(i, 1, n) maximize(ans, f[i][255]);
//        fto(i, 0, n) {
//            fto(b, 0, 255) printf("%d ", f[i][b]);
//            puts("");
//        }
    }

    printf("%d", ans);

    return 0;
}