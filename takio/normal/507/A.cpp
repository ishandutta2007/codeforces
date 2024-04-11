#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define LL long long
using namespace std;

vector <int> g[110] ,res;

int main () {
    int n, m, a;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        g[a].push_back (i);
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < (int) g[i].size (); j++) {
            m -= i;
            if (m < 0) goto x;
            res.push_back (g[i][j]);
        }
    }
    x:;
    cout << (int) res.size () << endl;
    for (int i = 0; i < (int) res.size (); i++) cout << res[i] << ' ';
}