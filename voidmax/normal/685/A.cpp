#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "input";

typedef long double base;

int LogN(int A) {
    if (A == 0) return 0;
    return LogN(A / 7) + 1;
}

int Clock(int A) {
    if (A == 1) return 1;
    return LogN(A - 1);
}

int n, m;
vector <int> arr;
set <string> ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    For(i, 0, 7) arr.pb(i);
    if (Clock(n) + Clock(m) > 7) {
        cout << 0 << endl;
        return 0;
    }
    while (true) {
        base cnt1 = 0, cnt2 = 0;
        string s = "";
        For(i, 0, 7) {
            if (i < Clock(n)) {
                cnt1 = cnt1 * 7 + arr[i];
            } else if (i < Clock(n) + Clock(m)) {
                cnt2 = cnt2 * 7 + arr[i];
            } else {
                break;
            }
            s += '0' + arr[i];
        }
        if (cnt1 < n && cnt2 < m) {
            ans.insert(s);
        }
        if (!next_permutation(arr.begin(), arr.end())) break;
    }
    cout << ans.size() << endl;
}