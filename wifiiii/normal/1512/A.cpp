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
        vector<int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        vector<int> aa=a;
        sort(aa.begin(),aa.end());
        int p=0;
        if(aa[0]!=aa[1]) p=aa[0];
        else p=aa.back();
        int ans=0;
        for(int i=0;i<n;++i) if(p==a[i]) ans=i+1;
        cout<<ans<<endl;
    }
}