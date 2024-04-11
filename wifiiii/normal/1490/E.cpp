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
        vector<int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        ll mx=0,sum=0;
        vector<int> aa=a;
        sort(a.begin(),a.end());
        for(int i=0;i<n;++i) {
            if(sum<a[i]) mx=a[i];
            sum+=a[i];
        }
        vector<int> ans;
        for(int i=0;i<n;++i) {
            if(aa[i]>=mx) ans.push_back(i);
        }
        cout<<ans.size()<<endl;
        for(int i:ans) cout<<i+1<<" ";cout<<endl;
    }
}