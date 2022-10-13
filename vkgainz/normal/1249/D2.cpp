#include <bits/stdc++.h>
using namespace std;
int dp[200005];
vector<pair<int,int>> seg[200005];
int main(){
    int n,k; 
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        seg[r].push_back({l,i});
        ++dp[r];
        --dp[l-1];
    }
    //for(int i=200000;i>=0;i--){
        //dp[i]+=dp[i+1];
    //}
    vector<int> ans;
    set<pair<int,int>> curr;
    for(int i=200000;i>=0;i--){
        dp[i]+=dp[i+1];
        for(auto x : seg[i]){
            curr.insert(x);
        }
        while(dp[i]>k){
            auto it = curr.begin();
            --dp[i];
            ++dp[(*it).first-1];
            ans.push_back((*it).second);
            curr.erase((*it));
        }
    }
    cout << ans.size() << endl;
    for(auto &it : ans) cout << it+1 << " ";
}