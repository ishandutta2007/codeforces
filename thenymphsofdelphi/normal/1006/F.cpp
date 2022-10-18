#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;
map <int, int> v[N][N];
int a[N][N];
int n, m, k, ans, h;

void h1(int x, int y, int val, int cnt){
    val ^= a[x][y];
    if (cnt == h){
        v[x][y][val]++;
        return;
    }
    if (y + 1 < m){
        h1(x, y + 1, val, cnt + 1);
    }
    if (x + 1 < n){
        h1(x + 1, y, val, cnt + 1);
    }
}

void h2(int x, int y, int val, int cnt){
    if (cnt == n + m - 2 - h){
        if (v[x][y].count(k ^ val)){
            ans += v[x][y][k ^ val];
        }
        return;
    }
    val ^= a[x][y];
    if (y > 0){
        h2(x, y - 1, val, cnt + 1);
    }
    if (x > 0){
        h2(x - 1, y, val, cnt + 1);
    }
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    h = (n + m - 2) / 2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    h1(0, 0, 0, 0);
    h2(n - 1, m - 1, 0, 0);
    cout << ans;
}