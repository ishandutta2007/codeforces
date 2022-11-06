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

string FileName = "minsumdiff";

typedef long long base;

string a;

int f(char a) {
    if ('0' <= a && a <= '9') return 0 + a - '0';
    if ('A' <= a && a <= 'Z') return 10 + a - 'A';
    if ('a' <= a && a <= 'z') return 36 + a - 'a';
    if (a == '-') return 62;
    return 63;
}

int cnt;

int Pow(base a, base b, base p) {
    base ans = 1;
    while (b != 0) {
        if (b & 1) ans = (ans * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> a;
    For(i, 0, a.size()) {
        For(j, 0, 6) {
            if (f(a[i]) & (1 << j)) {
                --cnt;
            }
        }
        cnt += 6;
    }
    cout << Pow(3, cnt, 1e9 + 7);
}