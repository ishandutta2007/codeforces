#include <bits/stdc++.h>
using namespace std;
int n,m;
int get(int x,int temp[]){
    int cnt = 0;
    for(int i=0;i<3;i++){
        int a = 0;
        if(x&(1<<i)){
            a = 1;
        }
        cnt+=abs(a-temp[i]);

    }
    return cnt;
}
bool work(int x,int y){
    int a[3], b[3];
    for(int i=0;i<3;i++){
        if(x&(1<<i)){
            a[i] = 1;
        }
        else{
            a[i] = 0;
        }
        if(y&(1<<i)){
            b[i] = 1;
        }
        else{
            b[i] = 0;
        }
    }
    if((a[0]+a[1]+b[0]+b[1])%2==1 && (a[1]+a[2]+b[1]+b[2])%2==1){
        return true;
    }
    return false;
}
int main(){
    cin >> n >> m;
    int grid[n][m];
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<m;j++){
            (s[j]=='0') ? grid[i][j] = 0 : grid[i][j] = 1;
        }
    }
    //check requirements
    if(n>=4){
        cout << -1 << endl;
        return 0;
    }
    if(n==1 || m==1){
        cout << 0 << endl;
        return 0;
    }
    //n = 2 or 3
    if(n==2){
        //alternative 1s and 0s
        int ret = 0;
        for(int i=0;i<m;i++){
            int gridSum =0;
            for(int j=0;j<n;j++) gridSum+=grid[j][i];
            if(i%2==0){
                ret+=(gridSum%2);
            }
            else{
                ret+=((gridSum+1)%2);
            }
        }
        int bet = 0;
        for(int i=0;i<m;i++){
            int gridSum = 0;
            for(int j=0;j<n;j++) gridSum+=grid[j][i];
            if(i%2==0){
                bet+=((gridSum+1)%2);
            }
            else{
                bet+=(gridSum)%2;
            }
        }
        cout << min(bet,ret) << endl;

    }
    else{
        //n=3, use dp?
        int dp[m][8];
        for(int i=0;i<m;i++){
            for(int j=0;j<8;j++){
                dp[i][j]= 1000000000;
            }
        }
        for(int j=0;j<8;j++){
            int temp[3];
            for(int i=0;i<3;i++) temp[i]= grid[i][0];
            dp[0][j] = get(j,temp);
        }
        int ret = 1000000000;
        for(int i=1;i<m;i++){
            for(int j=0;j<8;j++){
                 int temp[3];
                 for(int j=0;j<3;j++) temp[j] = grid[j][i];
                 int add = get(j,temp);
                 for(int k=0;k<8;k++){
                     if(work(j,k)){
                        dp[i][j] = min(dp[i][j],add+dp[i-1][k]);
                     }
                 }
                 if(i==m-1){
                     ret = min(ret,dp[i][j]);
                 }            
            }
            
        }
        cout << ret << endl;

    }

}