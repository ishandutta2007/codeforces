#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 2e5 + 5;
mt19937 rng(time(0));

char s[N];

int main() {
    cin >> (s + 1);
    int n = strlen(s + 1);
    rep(i, 1, n) s[i] -= 'A';
    bool flag = true;
    rep(i, 3, n) if (s[i] != (s[i - 1] + s[i - 2]) % 26) flag = false;
    cout << (flag ? "YES" : "NO");
    return 0;
}