#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), vis(n);
        for(int i=0;i<n;++i) {
            cin>>a[i];
            --a[i];
            vis[a[i]]=1;
        }
        set<int> s1, s2;
        for(int i=0;i<n;++i) if(!vis[i]) s1.insert(i),s2.insert(i);
        vector<int> ans1{a[0]},ans2{a[0]};
        for(int i=1;i<n;++i) {
            if(a[i]==a[i-1]) {
                ans1.push_back(*s1.begin());s1.erase(s1.begin());
                auto it=s2.lower_bound(a[i]);--it;
                ans2.push_back(*it);s2.erase(it);
            } else {
                ans1.push_back(a[i]);
                ans2.push_back(a[i]);
            }
        }
        for(int i:ans1) cout<<i+1<<" ";cout<<endl;
        for(int i:ans2) cout<<i+1<<" ";cout<<endl;
    }
}