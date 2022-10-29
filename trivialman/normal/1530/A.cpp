#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 1005;
mt19937 rng(time(0));

int T;
char s[N];

int main() {
    cin >> T;
    while(T--){
        cin >> (s+1);
        int n = strlen(s + 1);
        char ans = '0';
        rep(i, 1, n) ans = max(ans, s[i]);
        cout << ans << endl;
    }
    return 0;
}