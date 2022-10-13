#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dp[100001];
vector<pair<int,int>> ant;
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x,s; cin >> x >> s;
        ant.push_back({x,s});
    }
    for(int i=0;i<=m;i++) dp[i] = 1000000000;
    dp[0] = 0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            //extend to whole [1,m] segment
            //or extned to m and return dp[l-1]?
            dp[i] = min(dp[i],max(max(ant[j].first-ant[j].second-1,0),max(i-(ant[j].first+ant[j].second),0)));
            if(i<=(ant[j].first+ant[j].second)){
                dp[i] = min(dp[i],dp[max(ant[j].first-ant[j].second-1,0)]);
            }
            else{
                dp[i] = min(dp[i],i-(ant[j].first+ant[j].second)+dp[max(ant[j].first-ant[j].second-(i-(ant[j].first+ant[j].second))-1,0)]);
            }
        }
    }
    cout << dp[m] << endl;
}