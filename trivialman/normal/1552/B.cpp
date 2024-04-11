#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 5e4 + 5;
mt19937 rng(time(0));

int T, n;
int a[N][6];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) rep(j, 1, 5) scanf("%d", &a[i][j]);
        int maxi = 1;
        rep(i, 2, n) {
            int cnt = 0;
            rep(j, 1, 5) cnt += (a[maxi][j] < a[i][j]);
            if (cnt < 3)
                maxi = i;
        }

        bool ok = true;
        rep(i,1,n) if(i!=maxi){
            int cnt = 0;
            rep(j, 1, 5) cnt += (a[maxi][j] < a[i][j]);
            if (cnt < 3)
                ok = false;
        }
        printf("%d\n", ok ? maxi : -1);
    }
    return 0;
}