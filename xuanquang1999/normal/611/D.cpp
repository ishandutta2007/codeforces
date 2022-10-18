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
#define maxN 5005
#define MOD 1000000007
#define oo 3000000000000000000LL

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

int n, z[maxN][maxN], f[maxN][maxN], d[maxN][maxN];
string s;

void add(int &a, int b) {a = (a+b)%MOD;}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("matma.inp", "r", stdin);
        freopen("matma.out", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    cin >> s;
    s = "#"+s;

    fdto(i, n, 1) {
        fdto(j, n, 1) {
            z[i][j] = (s[i] == s[j]) ? (z[i+1][j+1]+1) : 0;
        }
    }

    f[0][0] = 1;
    fto(l, 0, n) d[0][l] = 1;
    fto(i, 1, n) {
        fto(l, 1, i) {
            int j = i-l+1;
            if (s[j] == '0') continue;
            f[i][l] = d[j-1][l-1];
//            printf("%d %d %d\n", i, l, j);
            if (j > l) {
                int k = j-l;
//                printf("%d\n", k);
                if (s[k] == '0') continue;
                if (z[k][j] < l && s[k+z[k][j]] < s[j+z[k][j]]) add(f[i][l], f[j-1][l]);
            }
        }
        fto(l, 1, n) d[i][l] = (d[i][l-1]+f[i][l])%MOD;
    }

//    fto(i, 1, n) {
//        fto(l, 1, n) printf("%d ", f[i][l]);
//        puts("");
//    }
//    puts("");
//    fto(i, 1, n) {
//        fto(l, 1, n) printf("%d ", d[i][l]);
//        puts("");
//    }

    printf("%d", d[n][n]);

    return 0;
}