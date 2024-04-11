#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#define pii pair <char. int>
#define LL long long
using namespace std;

const LL N = 1050;
int a[N], mp[N][N];
LL n, k, d, num;

int dfs(int dep){
    if (dep == d){
        num++;
        for (int i = 0; i < d; i++){
            mp[num][i] = a[i];
        }
        if (num == n) return 1;
        return 0;
    }
    for (int i = 1; i <= k; i++){
        a[dep] = i;
        if (dfs(dep + 1)) return 1;
    }
    return 0;
}

int main () {
    cin >> n >> k >> d;
    LL mx = 1;
    for (int i = 1; i <= d; i++){
        mx = mx * k;
        if (mx > 1050) break;
    }
    if (n > mx) {
        cout << -1;
        return 0;
    }
    dfs(0);
    for (int i = 0; i < d; i++){
        for (int j = 1; j <= n; j++){
            if (j != 1) printf (" ");
            printf ("%d", mp[j][i]);
        }
        printf ("\n");
    }
}