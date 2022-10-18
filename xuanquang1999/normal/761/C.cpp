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
#define maxN 55
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

int n, m, f[maxN][3];
char s[maxN][maxN];
string stNum = "0123456789", stChar = "*#&";

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, n-1) {
        scanf("%s", s[i]);
        fto(j, 0, 2) f[i][j] = maxN*3;
        fto(j, 0, m-1) {
            if (stNum.find(s[i][j]) != string::npos) f[i][0] = min(f[i][0], j, m-j);
            if (islower(s[i][j])) f[i][1] = min(f[i][1], j, m-j);
            if (stChar.find(s[i][j]) != string::npos) f[i][2] = min(f[i][2], j, m-j);
        }
    }

//    fto(i, 0, n-1) printf("%d %d %d\n", f[i][0], f[i][1], f[i][2]);

    int ans = maxN*3;
    fto(i, 0, n-1) {
        fto(j, 0, n-1) if (j != i) {
            fto(k, 0, n-1) if (k != j && k != i) {
                ans = min(ans, f[i][0]+f[j][1]+f[k][2]);
            }
        }
    }

    printf("%d", ans);

    return 0;
}