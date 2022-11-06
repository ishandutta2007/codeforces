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

const base p = 1e9 + 7;
base A, B, X, N;

base mul(base a, base b) {
    return a * b % p;
}

base sum(base a, base b) {
    return (a + b) % p;
}

pair <base, base> sum(pair <base, base> a, pair <base, base> b) {
    return {mul(a.x, b.x), sum(mul(a.y, b.x), b.y)};
}

pair <base, base> st = {1, 0};
pair <base, base> arr[62];

int main() {
    cin >> A >> B >> N >> X;
    arr[0].x = A;
    arr[0].y = B;
    For(i, 1, 62) arr[i] = sum(arr[i - 1], arr[i - 1]);
    For(i, 0, 62) {
        if (N & (((base)1) << i)) {
            st = sum(st, arr[i]);
        }
    }
    cout << (st.x * X + st.y) % p;

}