#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin>>n;
        map<int,int> mp;
        for(int i=0;i<n;++i) {
            int x;
            cin>>x;
            mp[x]++;
        }
        vector<int> a;
        for(auto p:mp) {
            a.push_back(p.second);
        }
        int ans=1e9;
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();++i) {
            ans=min(ans,(int)(n-(a.size()-i)*a[i]));
        }
        cout<<ans<<endl;
    }
}