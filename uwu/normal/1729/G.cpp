#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        string t;
        cin >> t;
        int n = s.size();
        int m = t.size();
        s = " " + s;
        vector<pair<int,int>>arr;
        arr.push_back({0,0});
        for(int i = m; i<=n; i++){
            if(s.substr(i-m+1,m)==t){
                arr.push_back({i-m+1,i});
            }
        }
        int len = arr.size();
        vector<int>mn(len,(int)1e9);
        mn[0] = 0;
        vector<int>dp(len);// the count
        dp[0] = 1;
        for(int i = 1; i<len; i++){
            for(int j = i; j<len; j++){
                if(arr[j].first<=arr[i].second){
                    int k = 0;
                    for(int a = i; a<len; a++){
                        if(arr[a].first<=arr[j].second){
                            k = a;
                        }
                    }
                    if(mn[i-1]+1<mn[k]){
                        mn[k] = mn[i-1]+1;
                        dp[k] = dp[i-1];
                    }
                    else if(mn[i-1]+1==mn[k]){
                        dp[k]+=dp[i-1];
                        dp[k]%=mod;
                    }
                }
            }
        }
        cout << mn[len-1] << " " << dp[len-1] << "\n";
    }
    return 0;
}