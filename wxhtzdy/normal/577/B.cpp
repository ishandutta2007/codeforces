#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
int a[N];
bool dp[N];
int main(){
    int n,m;scanf("%i %i",&n,&m);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]),a[i]%=m;
    if(n>=m){
        printf("YES");
        return 0;
    }
    for(int i=0;i<m;i++)dp[i]=0;
    for(int i=1;i<=n;i++){
        vector<int> all;
        for(int j=0;j<m;j++)if(dp[j])all.push_back((j+a[i])%m);
        for(int c:all)dp[c]=1;
        dp[a[i]]=1;
    }
    if(dp[0])printf("YES\n");
    else printf("NO\n");
    return 0;
}