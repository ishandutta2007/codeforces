#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
//typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 3e5 + 5;
mt19937 rng(time(0));

int T, n, x, lastx;

int reduce(string &str) {
    int sz = str.size(), res = 0, mul = 1;
    while (sz && str[sz - 1] >= '0' && str[sz - 1] <= '9') {
        res += mul * (str[sz - 1] - '0');
        mul *= 10;
        str.pop_back(), sz--;
    }
    if (str.size())
        str.pop_back();
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        string str = "";
        rep(i, 1, n) {
            cin >> x;
            if (x == 1) {
                str += (str.size() ? "." : "") + to_string(x);
            } else {
                while (reduce(str) + 1 != x)
                    ;
                str += (str.size() ? "." : "") + to_string(x);
            }
            cout << str << endl;
        }
    }
    return 0;
}