#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    int red[r];
    int green[g];
    int blue[b];
    for(int i=0;i<r;i++) cin >> red[i];
    for(int i=0;i<g;i++) cin >> green[i];
    for(int i=0;i<b;i++) cin >> blue[i];
    sort(red,red+r);
    sort(green,green+g);
    sort(blue,blue+b);
    int dp[r+1][g+1][b+1];
    for(int i=0;i<=r;i++)
        for(int j=0;j<=g;j++)
            for(int k=0;k<=b;k++)
                dp[i][j][k] = 0;
    for(int i=0;i<=r;i++){
        for(int j=0;j<=g;j++){
            for(int k=0;k<=b;k++){
                //match i,j
                if(i>=1 && j>=1)
                    dp[i][j][k] = max(dp[i][j][k],red[i-1]*green[j-1]+dp[i-1][j-1][k]);
                if(j>=1 && k>=1)
                    dp[i][j][k] = max(dp[i][j][k],green[j-1]*blue[k-1]+dp[i][j-1][k-1]);
                if(i>=1 && k>=1)
                    dp[i][j][k] = max(dp[i][j][k],red[i-1]*blue[k-1]+dp[i-1][j][k-1]);
                //match j,k
                //match i,k
            }
        }
    }
    cout << dp[r][g][b] << endl;
}