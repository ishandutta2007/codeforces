#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2050;
int n,a[N];
ll dp[N][N];
bool was[N][N];
ll Solve(int l,int r){
    if(l==r)return 0LL;
    if(was[l][r])return dp[l][r];
    was[l][r]=true;
    dp[l][r]=a[r]-a[l]+min(Solve(l+1,r),Solve(l,r-1));
    return dp[l][r];
}
int main(){
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    sort(a+1,a+n+1);
    printf("%lld",Solve(1,n));
    return 0;
}