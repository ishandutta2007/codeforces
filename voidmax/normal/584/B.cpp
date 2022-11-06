#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a; i > b; --i)
#define pb push_back
#define inf 1e9
#define x first
#define y second

using namespace std;

int n;
int Mod = 1e9 + 7;
long long ans1 = 1, ans2 = 1;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        ans1 *= 7;
        ans1 %= Mod;
    }
    For(i, 0, 3 * n) {
        ans2 *= 3;
        ans2 %= Mod;
    }
    ans2 -= ans1; if (ans2 < 0) ans2 += Mod;
    cout << ans2 << endl;
}