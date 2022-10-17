#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<pii> arr; arr.push_back({0,0});
        for (int i=0,a,b;i<n;++i){
            cin >> a >> b;
            arr.push_back({a,b});
        }
        bool ans=true;
        for (int i=1;i<=n;++i){
            if (arr[i].second-arr[i-1].second>arr[i].first-arr[i-1].first||arr[i].first<arr[i-1].first||arr[i].second<arr[i-1].second){
                ans=false;
            }
        }
        if (ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }
}