#include <cstdio>
using namespace std;
int a[30001];
bool dp[30001];
int main(){
    int n,t,i;
    scanf("%d%d",& n,& t);
    for(i = 1; i < n; i ++)
        scanf("%d",a+i);
    dp[1] = 1;
    for(i = 1; i < t; i ++)
        if(dp[i])
            dp[i+a[i]] = 1;
    if(dp[t])
        puts("YES");
    else
        puts("NO");
    return 0;
}