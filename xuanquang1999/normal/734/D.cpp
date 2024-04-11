//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ftoa(i, l, r, a) for(int i = (l); i <= (r); i += a)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 500005
#define oo 5000000000000000000LL

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

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, xO, yO, minI[8], x[maxN], y[maxN];
char c[maxN];
bool check[256][8];

ll dist(ll x, ll y) {
    return abs(x)+abs(y);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ftoa(i, 0, 7, 2) check['R'][i] = true;
    ftoa(i, 1, 7, 2) check['B'][i] = true;
    fto(i, 0, 7) check['Q'][i] = true;

    scanf("%d%d%d\n", &n, &xO, &yO);
    fto(i, 1, n) scanf("%c%d%d\n", &c[i], &x[i], &y[i]);

    fto(i, 1, n) x[i] -= xO, y[i] -= yO;

    fto(i, 1, n) {
        fto(d, 0, 7) {
            if (x[i]*dy[d] == y[i]*dx[d] && x[i]*dx[d] >= 0 && y[i]*dy[d] >= 0) {
                if (minI[d] == 0 || dist(x[minI[d]], y[minI[d]]) > dist(x[i], y[i])) minI[d] = i;
            }
        }
    }

    fto(d, 0, 7) {
        if (minI[d] != 0 && check[c[minI[d]]][d]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");

    return 0;
}