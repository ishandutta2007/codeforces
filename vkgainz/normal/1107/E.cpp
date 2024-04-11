#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll maxGet[101];
ll dp[101][101][301];
int main(){
    cin >> n;
    int a[n];
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int> vals; 
    for(int i=0;i<n;i++){
        int j=i;
        while(j<n && s[j]==s[i]){
            j++;
        }
        vals.push_back(j-i);
        i= j-1;
    }
    maxGet[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=i){
                maxGet[i] = max(maxGet[i],maxGet[i-j]+a[j-1]);
            }
        }
    }
    int x = vals.size();
    for(int len=1;len<=x;len++){
        for(int i=0;i<x;i++){
            for(int put=0;put<=n;put++){
                int j = i+len-1;
                if(j>=x || j<i) continue;

                //dp[i][j][put]= last one has put nums, from vals[i....j]
                for(int r=j;r>=i;r-=2){
                    if(r==j){
                        if(j>0){
                            dp[i][j][put] = maxGet[put]+dp[i][j-1][vals[j-1]];
                        }
                        else{
                            dp[i][j][put] = maxGet[put];
                        }
                    }
                    else{
                        if(put+vals[r] <=n){
                            dp[i][j][put] = max(dp[i][j][put],dp[r+1][j-1][vals[j-1]]+dp[i][r][put+vals[r]]);
                        }
                    }
                }
            }
        }
    }
    cout << dp[0][x-1][vals[x-1]] << endl;
}