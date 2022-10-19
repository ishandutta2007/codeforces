#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/19, 23:35:24
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

bool solve() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--) {
        int x;
        cin >> x;
        pq.push(x);
    }
    while (!pq.empty()) {
        int x = pq.top(); pq.pop();
        if (x == 2048) return 1;
        if (x > 2048) return 0;
        if (pq.empty()) return 0;
        int y = pq.top();
        if (x != y) continue;
        pq.pop();
        pq.push(x + y);
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) printf(solve() ? "YES\n" : "NO\n");
    return 0;
}