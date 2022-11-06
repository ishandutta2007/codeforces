#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <time.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "train";

int f(int a, int p) {
    int Pow = p;
    int cnt = 0;
    while (Pow <= a) {cnt += a / Pow; Pow *= p;}
    return cnt;
}

int f10(int a) {
    return min(f(a, 2), f(a, 5));
}

int n;
vector <int> ans;

main() {
    //files(FileName);
    cin >> n;
    For(i, 1, n * 10) {
        if (f10(i) > n) break;
        if (f10(i) == n) ans.pb(i);
    }
    cout << ans.size() << endl;
    For(i, 0, ans.size()) cout << ans[i] << ' ';
}