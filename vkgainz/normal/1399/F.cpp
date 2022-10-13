#include <bits/stdc++.h>
using namespace std;
void solve_case(){
    int n; cin >> n;
    set<int> compress;
    vector<int> point[6005];
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int l,r; cin >> l >> r;
        compress.insert(l); compress.insert(r);
        v.push_back({l,r});
    }
    map<int,int> idx;
    int cnt = 0;
    for(auto &it : compress){
        idx[it] = ++cnt;
    }
    for(int i=0;i<n;i++){
        point[idx[v[i].second]].push_back(idx[v[i].first]);
    }
    for(int i=0;i<6005;i++){
        sort(point[i].begin(),point[i].end(),greater<int>());
    }
    int dp[2*n+5][2*n+5];
    for(int i=0;i<2*n+5;i++){
        for(int j=0;j<2*n+5;j++){
            dp[i][j] = 0;
        }
    }
    for(int len = 1;len<=2*n+1;len++){
        for(int i=1;i<=2*n;i++){
            int j = i+len-1;
            if(j>2*n) continue;
            int add = 0;
            int best =0;
            for(int l : point[j]){
                if(l<i) break;
                if(l==i){
                    add++;
                }
                else{
                    best = max(best,dp[l][j]+dp[i][l-1]);
                }
            }
            dp[i][j] = best;
            dp[i][j] = max(dp[i][j],dp[i][j-1])+add;
        }
    }
    cout << dp[1][2*n] << endl;
    
}
int main(){
    int t; cin >> t;
    while(t--){
        solve_case();
    }
}