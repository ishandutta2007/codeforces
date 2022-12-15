#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 105;
ll dp[MN][MN][MN], n, c[MN], i, x, nxt[MN];
string s;
ll solve(int l,int r,int pre){
    if(l>r) return 0;
    else if(nxt[l]>r) return c[r-l+1+pre];
    else if(dp[l][r][pre]!=-1) return dp[l][r][pre];
    for(int p=l;p<=r&&nxt[p]<=r&&p;p=nxt[nxt[p]])
        dp[l][r][pre] = max(dp[l][r][pre], solve(nxt[l],nxt[nxt[p]]-1,0)+solve(nxt[nxt[p]],r,pre+nxt[l]-l));
    dp[l][r][pre] = max(dp[l][r][pre], c[pre+nxt[l]-l]+solve(nxt[l],r,0));
    return dp[l][r][pre];
}
int main(){
    cin >> n >> s;
    s.insert(s.begin(),' ');
    s.push_back(' ');
    for(i=1;i<=n;i++)scanf("%lld",&c[i]);
    for(i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            c[i]=max(c[i],c[j]+c[i-j]);
        }
    }
    for(i=n;i>=1;i--){
        if(s[i]!=s[i+1]) nxt[i]=i+1;
        else nxt[i]=nxt[i+1];
    }
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",solve(1,n,0));
    return 0;
}