#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define LL long long

using namespace std;

vector <int> g[2010], k[10];

void f () {
    int flag = 0;
    for (int i = 1; i <= 2000; i++) {
        int sz = g[i].size();
        if (sz == 2) k[2].push_back(i);
        if (sz > 2) k[3].push_back(i);
        for (int j = 0; j < sz; j++) {
            if (flag) cout << ' ';
            flag = 1;
            cout << g[i][j];
        }
    }
    cout << endl;
}

int main () {
    int n, cnt = 0, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        g[a].push_back(i);
        if (g[a].size() >= 2) cnt++;
    }
    if (cnt < 2) {
        printf ("NO\n");
        return 0;
    }
    printf ("YES\n");
    f();
    if (k[3].size() == 0) {
        int t = k[2][0];
        swap (g[t][0], g[t][1]);
        f ();
        t = k[2][1];
        swap (g[t][0], g[t][1]);
        f ();
    } else {
        int t = k[3][0];
        swap (g[t][0], g[t][1]);
        f();
        swap (g[t][0], g[t][2]);
        f();
    }
}