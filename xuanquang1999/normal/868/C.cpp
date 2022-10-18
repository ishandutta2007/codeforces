//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
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
#define maxN 100005
#define oo 2000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

bool isOn(int b, int i) {return (b>>i)&1;}

int n, k, a[maxN][4], cnt[16];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n) fto(j, 0, k-1) scanf("%d", &a[i][j]);

    fto(i, 1, n) {
        int b = 0;
        fto(j, 0, k-1) {
            if (a[i][j]) b |= (1<<j);
        }
        ++cnt[b];
    }

//    fto(i, 0, (1<<k)-1) printf("%d ", cnt[i]);
//    puts("");

    fto(b, 1, (1<<(1<<k))-1) {
        bool ok = true;

        fto(i, 0, (1<<k)-1) {
            if (isOn(b, i) && cnt[i] == 0) {
                ok = false;
                break;
            }
        }

        vector<int> p(k, 0);
        int sum = 0;
        fto(i, 0, (1<<k)-1) {
            if (isOn(b, i)) {
                ++sum;
                fto(j, 0, k-1) {
                    if (isOn(i, j)) ++p[j];
                }
            }
        }

        fto(j, 0, k-1) {
            if (p[j] > sum/2) {
                ok = false;
                break;
            }
        }

        if (ok) {
//            debug(b);
            puts("YES");
            return 0;
        }
    }

    puts("NO");

    return 0;
}