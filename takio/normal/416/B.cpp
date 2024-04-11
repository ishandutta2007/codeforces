#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int a[50010][10], dp[50010][10];

int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
//            if(i == 1) dp[i][j] = a[i][j];
//                else
            dp[i][j] = max (dp[i-1][j], dp[i][j-1]) + a[i][j];
            if(j == m){
                if(i != 1) cout << ' ';
                cout << dp[i][j];
            }
        }
}