//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
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
#define oo 1000000007
#define EPS 1e-7

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

double prob(int d, int k) {
    double ans = 1;
    fto(i, 1, k) ans *= 1.0*(d-k+i)/(d+i-1);
    return ans;
}

int k;
double f[10*maxN][maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int k, q;
    scanf("%d%d", &k, &q);
    f[0][0] = 1;
    fto(ik, 0, 10*k-1) {
        fto(i, 0, k) {
            if (f[ik][i] > 1e-12) {
                //debug(f[ik][i]);
                f[ik+1][i+1] += f[ik][i]*(k-i)/k;
                f[ik+1][i] += f[ik][i]*i/k;
            }
        }
    }
//    fto(i, 0, 3*k) {
//        fto(j, 0, k) printf("%.9f ", f[i][j]);
//        puts("");
//    }

    fto(i, 1, q) {
        int p; scanf("%d", &p);
//        debug(p);
        int l = k, r = 10*k, res = r+1;
        while (l <= r) {
            int mid = (l+r)/2;
            //printf("%d %.9f\n", mid, prob(mid, k));
            if (f[mid][k] >= (p-EPS)/2000) {
                res = mid;
                r = mid-1;
            } else l = mid+1;
        }

        printf("%d\n", res);
    }

    return 0;
}