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

typedef long long base;

int n;
string arr[1001];


int main() {
    //read(FileName);
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) cin >> arr[i];
    int cnt = 6;
    For(i, 0, n) {
        For(j, i + 1, n) {
            int m = 0;
            For(k, 0, 6)
                if (arr[i][k] != arr[j][k])
                    ++m;
            m = (m + 1) / 2;
            cnt = min(cnt, m - 1);
        }
    }
    cout << cnt << endl;
}