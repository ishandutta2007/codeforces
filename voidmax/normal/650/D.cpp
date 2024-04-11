#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "input";

typedef long long base;

int n, m;
int X;
int nvp[400001];
vector <point> func;
map <int, int> ans[400001][2];
vector <int> arr;
set <int> num[400001];
int a[400001];

int BinSearch(int S, bool Less) {
    int L = 0, R = X + 1;
    while (R - L > 1) {
        int M = (R + L) >> 1;
        if ((a[M] != S) && ((a[M] < S) ^ Less)) {
            L = M;
        } else {
            R = M;
        }
    }
    return L;
}

int main() {
    //read(FileName);
    //ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    For(i, 0, n) {
        int a; cin >> a;
        arr.pb(a);
    }
    For(i, 0, m) {
        int a, b; scanf("%d%d", &a, &b); --a;
        num[a].insert(b);
        func.pb({a, b});
    }
    X = 0;
    a[0] = 0;
    For(Less, 0, 2) {
        X = 0;
        if (Less) a[0] = 1e9 + 1; else a[0] = 0;
        For(id, 0, n) {
            int i = id; if (Less) i = n - i - 1;
            for(int j: num[i]) {
                ans[i][Less][j] = BinSearch(j, Less);
            }
            int L = BinSearch(arr[i], Less);
            if (L == X) {
                ++X; a[X] = arr[i];
            } else {
                if (Less) a[L + 1] = max(a[L + 1], arr[i]);
                else      a[L + 1] = min(a[L + 1], arr[i]);
            }
            ans[i][Less][arr[i]] = L;
        }
    }
    For(i, 0, n) {
        int L = ans[i][0][arr[i]];
        int R = ans[i][1][arr[i]];
        if (L + R + 1 == X) ++nvp[L];
    }
    For(j, 0, m) {
        int i = func[j].x;
        int L = ans[i][0][func[j].y];
        int R = ans[i][1][func[j].y];
        if (L + R + 1 >= X) {
            printf("%d\n", L + R + 1);
            continue;
        }
        if (ans[i][0][arr[i]] + ans[i][1][arr[i]] + 1 == X) {
            if (nvp[ans[i][0][arr[i]]] == 1) {
                printf("%d\n", X - 1);
                continue;
            }
        }
        printf("%d\n", X    );
    }
}