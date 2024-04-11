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

int a1 = 1234567, a2 = 123456, a3 = 1234;
int n;

int main() {
    ios::sync_with_stdio(false);
    //read(FileName);
    cin >> n;
    For(i, 0, n / a1 + 1) {
        int n1 = n - i * a1;
        For(j, 0, n1 / a2 + 1) {
            int n2 = n1 - j * a2;
            if (n2 % 1234 == 0) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}