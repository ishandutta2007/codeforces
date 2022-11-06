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

base a, b;
base cnt;

bool good(int a) {
    if (a % 400 == 0) {
        return true;
    } else if (a % 4 == 0 && a % 100 != 0) {
        return true;
    } else {
        return false;
    }
}

void Next() {
    if (good(a)) {
        cnt += 366;
    } else {
        cnt += 365;
    }
    ++a;
    cnt %= 7;
}

int main() {
    cin >> a; b = a;
    Next();
    while (cnt != 0 || (good(a) != good(b))) {
        Next();
    }
    cout << a << endl;
}