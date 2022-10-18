//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
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
#define X real()
#define Y imag()
#define maxN 100005
#define oo 2000000007
#define EPS 1e-9

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

ll n, u;
int q, k;
char s[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%lld%d", &n, &q);
    fto(i, 1, q) {
        scanf("%lld", &u);
        scanf("%s", s); k = strlen(s);

        fto(i, 0, k-1) {
            if (s[i] == 'L') {
                u -= (u&(-u))/2;
            } else if (s[i] == 'R') {
                u += (u&(-u))/2;
            } else if (u != (n+1)/2) {
                bool right = false;
                fto(i, 0, 60) {
                    if (right) break;
                    if (((u>>i)&3LL) == 3LL) right = true;
                    if ((u>>i)&1) break;
                }
                if (right) u -= (u&(-u));
                else u += (u&(-u));
            }
        }

        printf("%lld\n", u);
    }


    return 0;
}