#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m, a[110][110];

int dfs(int k)
{
//    cout << k;
    if(k % 2) return k;
    for(int i = 1; i <= k / 2; i++)
        for(int j = 1; j <= m; j++)
        if(a[i][j] != a[k - i + 1][j]) return k;
    return dfs(k/2);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        cin >> a[i][j];
    cout << dfs(n);
}