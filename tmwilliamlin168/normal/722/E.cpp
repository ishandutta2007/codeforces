#include <bits/stdc++.h>
using namespace std;

const int MOD=1000000007;
int N, M, K, S;
int fact[200001];
int ifact[200001];

int powmod(int a, int b) {
    int ret=1;
    for(; b>0; b/=2) {
        if(b&1)
            ret=1LL*ret*a%MOD;
        a=1LL*a*a%MOD;
    }
    return ret;
}

int C(int n, int k) {
    return 1LL*fact[n]*ifact[k]%MOD*ifact[n-k]%MOD;
}

int ways(int n, int m) {
    return C(n+m, n);
}

pair<int, int> A[2000];
int X[2000];
int Y[2000];
int dp[2000][22];
int ans[22];

void addmod(int& x, int v) {
    x+=v;
    if(x>=MOD)
        x-=MOD;
}

void submod(int& x, int v) {
    addmod(x, MOD-v);
}

int main() {
    fact[0]=1;
    for(int i=1; i<=200000; i++)
        fact[i]=1LL*fact[i-1]*i%MOD;
    for(int i=0; i<=200000; i++)
        ifact[i]=powmod(fact[i], MOD-2);
    scanf("%d%d%d%d", &N, &M, &K, &S);
    for(int i=0; i<K; i++)
        scanf("%d%d", &A[i].first, &A[i].second), A[i].first--, A[i].second--;
    sort(A, A+K);
    for(int i=0; i<K; i++)
        tie(X[i], Y[i])=A[i];
    for(int i=0; i<K; i++) for(int x=1; x<=21; x++) {
        dp[i][x]=ways(X[i], Y[i]);
        for(int j=0; j<i; j++) if(X[j]<=X[i] && Y[j]<=Y[i])
            submod(dp[i][x], 1LL*dp[j][x]*ways(X[i]-X[j], Y[i]-Y[j])%MOD);
        for(int j=0; j<x; j++)
            submod(dp[i][x], dp[i][j]);
    }
    for(int x=0; x<=20; x++) {
        ans[x]=ways(N-1, M-1);
        for(int i=0; i<K; i++)
            submod(ans[x], 1LL*dp[i][x+1]*ways(N-1-X[i], M-1-Y[i])%MOD);
        for(int i=0; i<x; i++)
            submod(ans[x], ans[i]);
    }
    int tot=ways(N-1, M-1);
    int rans=0;
    for(int i=0; i<=20; i++) {
        submod(tot, ans[i]);
        addmod(rans, 1LL*S*ans[i]%MOD);
        S-=S/2;
    }
    addmod(rans, tot);
    rans=1LL*rans*powmod(ways(N-1, M-1), MOD-2)%MOD;
    printf("%d\n", rans);
}