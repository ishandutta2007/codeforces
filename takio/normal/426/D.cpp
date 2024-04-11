#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
int a[110][110];

void solve1() {
    int mn = 1e9;
    for (int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= n; j++)
        if(j == i) continue;
        else
        {
            int t = 0, f = 0;
            for(int k = 1; k <= m; k++)
            {
                if(a[i][k] == a[j][k]) t++;
                else f++;
            }
            sum += m - max (t, f);
        }
        mn = min (mn, sum);
//        cout << sum << ' ';
    }
    if(mn > k) cout << "-1";
    else cout << mn;
}

void solve2() {
    int mn = 1e9;
    int rec[110];
    for(int i = 0; i <= (1 << n) - 1; i++)
    {
        for(int j = 1; j <= n; j++){
            if ((1 << j - 1) & i) rec[j] = 1; else rec[j] = 0;
//            cout << rec[j];
        }

//        cout << endl;
        int sum = 0;
        for(int j = 1; j <= m; j++){
            int t = 0, f = 0;
            for(int k = 1; k <= n; k++)
                if(a[k][j] == rec[k]) t++;
                else f++;
//            cout << t << f << endl;
            sum += n - max (t, f);
        }
        mn = min (mn, sum);
//        cout << sum << endl ;
    }
    if(mn > k) cout << "-1";
    else cout << mn;
}

int main() {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    if(n > k) solve1();
    else solve2();
}