#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n+2);
        for(int i=0;i<n+2;++i) cin>>a[i];
        sort(a.begin(),a.end());
        auto chk = [&](ll s) {
            ll sum=accumulate(a.begin(),a.end(),0ll);
            map<ll,int> mp;
            for(int i=0;i<n+2;++i) mp[a[i]]++;
            mp[s]--;
            sum-=s;
            if(mp[sum-s]) {
                mp[sum-s]--;
            } else {
                return 0;
            }
            vector<int> ans;
            for(auto p:mp) for(int i=0;i<p.second;++i) ans.push_back(p.first);
            sort(ans.begin(),ans.end());
            for(int i:ans) cout<<i<<" ";cout<<endl;
            return 1;
        };
        if(!chk(a.back()) && !chk(a[a.size()-2])) cout<<-1<<endl;
    }
}