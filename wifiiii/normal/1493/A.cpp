#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ans;
        for(int i=k+1;i<=n;++i) ans.push_back(i);
        for(int i=k-1;i>=(k+1)/2;--i) ans.push_back(i);
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(int i:ans) cout<<i<<" ";cout<<endl;
    }
}