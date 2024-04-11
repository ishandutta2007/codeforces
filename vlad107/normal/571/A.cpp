#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl

using namespace std;

const int N = -1;
const int INF = 1e9 + 19;

int a, b, c, l;
long long ans;

void solve(int a, int b, int c) {
    for (int x = 0; x <= l; x++) {
        int R = min(c + x - a - b, l - x);
        if (R < 0) continue;
        ans -= (R + 1) * 1LL * (R + 2) / 2;
    }
}

int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif 
    cin >> a >> b >> c >> l;
    ans = 0;
    for (int x = 0; x <= l; x++) {
        int R = l - x;
        ans += (R + 1) * 1LL * (R + 2) / 2;
    }
    solve(a, b, c);
    solve(a, c, b);
    solve(b, c, a);
    cout << ans << endl;
}