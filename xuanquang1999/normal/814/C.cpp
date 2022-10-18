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
#define X real()
#define Y imag()
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

int n, q, f[maxN][26];
string s;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    cin >> s;

    fto(c, 'a', 'z') {
        fto(l, 0, n-1) {
            int cnt = 0;
            fto(r, l, n-1) {
                cnt += (c != s[r]);
                f[cnt][c-'a'] = max(f[cnt][c-'a'], r-l+1);
            }
        }
        fto(i, 1, n) f[i][c-'a'] = max(f[i][c-'a'], f[i-1][c-'a']);
//        printf("%c\n", c);
//        fto(i, 0, n) printf("%d ", f[i][c-'a']);
//        puts("");
    }


    scanf("%d", &q);
    fto(i, 1, q) {
        int m; char s[2];
        scanf("%d%s", &m, s);
        printf("%d\n", f[m][s[0]-'a']);
    }

    return 0;
}