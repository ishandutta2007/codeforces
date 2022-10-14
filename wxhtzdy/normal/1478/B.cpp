#include <bits/stdc++.h>
using namespace std;
bool Valid(int x,int d){
    while(x>0){
        if(x%10==d)return true;
        x/=10;
    }
    return false;
}
const int N=105;
bool dp[10][N];
int main(){
    for(int i=1;i<=9;i++){
        dp[i][0]=1;
        for(int j=1;j<N;j++)if(Valid(j,i)){
            for(int k=1;k<N;k++)if(k>=j&&dp[i][k-j])dp[i][k]=1;
        }
    }
    int t;scanf("%i",&t);
    while(t--){
        int q,d;scanf("%i%i",&q,&d);
        while(q--){
            int x;scanf("%i",&x);
            if(x>=100)printf("YES\n");
            else{
                if(dp[d][x])printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}