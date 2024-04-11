#include <cstring>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

#define pii pair<int, int>

int main () {
    int n, m, a;
    cin >> n >> m;
    queue <pii> q;
    for (int i = 1; i <= n ;i++)
    {
        cin >> a;
        q.push(pii(a, i));
    }
    int res;
    while (!q.empty()){
        pii u = q.front();
        q.pop();
        res = u.second;
        int x = u.first;
        if (x > m) q.push(pii(x - m, res));
    }
    cout << res;
}