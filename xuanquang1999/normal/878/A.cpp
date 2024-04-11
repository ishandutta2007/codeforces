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
#define maxN 500005
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

int n, x[maxN], truthTable[2][10], ans[3][10];
char op[maxN], ansOp[3] = {'&', '|', '^'};

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d\n", &n);
    fto(i, 1, n) scanf("%c%d\n", &op[i], &x[i]);

    fto(c, 0, 9) {
        fto(b, 0, 1) {
            truthTable[b][c] = b;
            fto(i, 1, n) {
                int y = (x[i]>>c)&1;
                if (op[i] == '|') truthTable[b][c] |= y;
                if (op[i] == '^') truthTable[b][c] ^= y;
                if (op[i] == '&') truthTable[b][c] &= y;
            }
        }
        ans[0][c] = (truthTable[0][c] || truthTable[1][c]);
        ans[1][c] = (truthTable[0][c] && truthTable[1][c]);
        ans[2][c] = (truthTable[0][c] && !truthTable[1][c]);
    }

    puts("3");
    fto(i, 0, 2) {
        int x = 0;
        fto(c, 0, 9) x |= (ans[i][c]<<c);
        printf("%c %d\n", ansOp[i], x);
    }


    return 0;
}