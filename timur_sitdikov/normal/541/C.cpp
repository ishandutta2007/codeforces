
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <functional>
#include <cctype>
#include <climits>
#include <string>
#include <utility>
using namespace std;

typedef unsigned long long ull;

ull gcd(ull a, ull b) {
    return b == 0 ? a : gcd(b, a % b);
}

ull lcm(ull a, ull b) {
    return (a / gcd(a, b)) * b;
}

int main () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int f[300];
    for (int i = 0; i < n; ++i) cin >> f[i];
    for (int i = 0; i < n; ++i) --f[i];

    int v[300];
    ull maximal = 0;
    ull cycles = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) v[j] = -1;
        v[i] = 0;
        int cur = i;
        int next;
        for (int j = 0; j < n + n; ++j) {
            next = f[cur];
            if (v[next] == -1) {
                v[next] = v[cur] + 1;
                cur = next;
            } else {
                if (ull(v[next]) > maximal) maximal = ull(v[next]);
                cycles = lcm(cycles, ull(v[cur] + 1 - v[next])); //!!
                break;
            }
        }
    }

    if (maximal == 0) {
        cout << cycles;
    } else {
        ull answer = cycles;
        while (answer < maximal) answer += cycles;
        cout << answer;
    }

    return 0;
}