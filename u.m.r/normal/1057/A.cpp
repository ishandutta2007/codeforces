#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int a[MAXN];
int dfs(int u){
    if (u == 1) putchar('1');
    else {
        dfs(a[u]);
        printf(" %d", u);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        scanf("%d", &a[i]);
    dfs(n);
    puts("");
    return 0;
}