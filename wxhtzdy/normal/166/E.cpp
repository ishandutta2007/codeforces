#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int md=1000000007;
void add(int& x,int y){x+=y;if(x>md)x-=md;}
int main(){
    int n;
    scanf("%i",&n);
    int dp[2][4];
    dp[0][0]=(int) 0;
    dp[0][1]=(int) 0;
    dp[0][2]=(int) 0;
    dp[0][3]=(int) 1;
    dp[1][0]=(int) 1;
    dp[1][1]=(int) 1;
    dp[1][2]=(int) 1;
    dp[1][3]=(int) 0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<4;j++) dp[i&1][j]=0;
        add(dp[i&1][0],dp[(i-1)&1][1]);
        add(dp[i&1][0],dp[(i-1)&1][2]);
        add(dp[i&1][0],dp[(i-1)&1][3]);
        add(dp[i&1][1],dp[(i-1)&1][0]);
        add(dp[i&1][1],dp[(i-1)&1][2]);
        add(dp[i&1][1],dp[(i-1)&1][3]);
        add(dp[i&1][2],dp[(i-1)&1][0]);
        add(dp[i&1][2],dp[(i-1)&1][1]);
        add(dp[i&1][2],dp[(i-1)&1][3]);
        add(dp[i&1][3],dp[(i-1)&1][0]);
        add(dp[i&1][3],dp[(i-1)&1][1]);
        add(dp[i&1][3],dp[(i-1)&1][2]);
    }
    printf("%lld",dp[n&1][3]);
}