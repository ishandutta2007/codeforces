#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> up(m, n - 1), nxt(m), lst(m);
    for(int i = 0; i < m; ++i) nxt[i] = i + 1, lst[i] = i - 1;
    int f = 0;
    auto upd = [&]() {
        for(int i = f; i < m; i = nxt[i]) {
            while(up[i] && a[up[i]][i] == 2) {
                --up[i];
            }
            if(up[i] == -1) {
                if(lst[i] != -1) nxt[lst[i]] = nxt[i];
                if(nxt[i] != n) lst[nxt[i]] = lst[i];
                if(i == f) f += 1;
            }
        }
    };
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < k; ++i) {
        int y;
        cin >> y;
        --y;
        int x = 0;
        while(x < n) {
            if(a[x][y] == 2) {
                x += 1;
            } else if(a[x][y] == 3) {
                a[x][y] = 2;
                y -= 1;
            } else if(a[x][y] == 1) {
                a[x][y] = 2;
                y += 1;
            }
            if(x > up[y]) break;
        }
        upd();
        cout << y + 1 << ' ';
    }
    cout << endl;
}

/*
5 5 5
1 2 3 3 3
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2
2 2 2 2 2
5 4 3 2 1
*/