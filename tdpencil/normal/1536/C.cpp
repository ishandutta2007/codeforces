#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5, M = 1e9+7;
#define runcase LOL


void solve(int test_case = 0)
{
    int n; cin >> n;
    string s;
    cin >> s;
    unordered_map<double, int> cnt;

    int d = 0, k = 0;
    // drift king??

    for(char ch : s) {
        if(ch == 'D') ++d;
        if(ch == 'K') ++k;

        cout << ++cnt[(double)d / (double)k] << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
#ifdef runcase
    cin >> T;
#endif

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}