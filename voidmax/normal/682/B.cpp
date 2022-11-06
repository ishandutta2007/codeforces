#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

typedef long long base;

int n;
vector <int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        int a; cin >> a;
        arr.pb(a);
    }
    sort(arr.begin(), arr.end());
    int cnt = 1;
    For(i, 0, n) {
        if (arr[i] < cnt) continue;
        ++cnt;
    }
    cout << cnt << endl;
}