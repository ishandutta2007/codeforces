#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int n, i, x, sz[3*MN], sm[3*MN], ans;

void dfs(int n){
    if(n>MN) return;
    dfs(2*n), dfs(2*n+1);
    sm[n] = sm[2*n]+sm[2*n+1]+sz[2*n]+sz[2*n+1];
    sz[n] += sz[2*n]+sz[2*n+1];
}

void solve(int n,int c,int m,int g){
    if(!sz[n]) return;
    int a = sz[n]-sz[2*n]-sz[2*n+1];
    ans = min(ans, m+sm[n]);
    if(sz[2*n]&&sz[2*n+1]){
        if(sz[2*n]>sz[2*n+1]){
            c += sz[2*n+1]+a;
            m += sm[2*n+1]+sz[2*n+1];
            solve(2*n,c,m+c,1);
        }
    }
    else if(sz[2*n]) solve(2*n,c+a,m+c+a,g);
    else if(!a&&!g) solve(2*n+1,c+a,m+c+a,g);
}

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&x);
        sz[x]++;
    }
    ans = 1<<30;
    dfs(1);
    solve(1,0,0,0);
    printf("%d\n",ans);
    return 0;
}