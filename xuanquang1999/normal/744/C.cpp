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
#define maxN 16
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

void minimize(int &a, int b) {a = min(a, b);}
void maximize(int &a, int b) {a = max(a, b);}

int n, sumR, sumB, f[1<<maxN][maxN*maxN+1], r[maxN], b[maxN];
char c[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d\n", &n);
    int cntR = 0;
    fto(i, 0, n-1) {
        scanf("%c%d%d\n", &c[i], &r[i], &b[i]);
        sumR += r[i]; sumB += b[i];
        if (c[i] == 'R') ++cntR;
    }

//    fto(i, 0, n-1) printf("%c %d %d\n", c[i], r[i], b[i]);

    int maxSR = n*n;
    fto(bi, 0, (1<<n)-1) {
        fto(sr, 0, maxSR) f[bi][sr] = -oo;
    }
    f[0][0] = 0;

    fto(bi, 0, (1<<n)-1) {
        int cntB = 0, cntR = 0;
        fto(i, 0, n-1) {
            if ((bi>>i)&1) {
                if (c[i] == 'R') ++cntR;
                else ++cntB;
            }
        }
//        printf("%d %d %d\n", bi, cntB, cntR);
        fto(sr, 0, maxSR) {
            int sb = f[bi][sr];
            fto(i, 0, n-1) {
                if (!((bi>>i)&1)) {
                    int SR = sr + min(r[i], cntR);
                    int SB = sb + min(b[i], cntB);
//                    printf("%d %d %d %d %d\n", i, sr, sb, SR, SB);
                    maximize(f[bi|(1<<i)][SR], SB);
                }
            }
        }
    }
//    fto(bi, 0, (1<<n)-1) {
//        fto(sr, 0, maxSR) printf("%d ", f[bi][sr]);
//        puts("");
//    }
    int ans = oo;
    fto(sr, 0, maxSR) {
        int sb = f[(1<<n)-1][sr];
        minimize(ans, max(sumR-sr, sumB-sb)+n);
    }

    printf("%d", ans);

    return 0;
}