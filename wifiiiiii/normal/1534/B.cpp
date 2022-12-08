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
        vector<int> a(n+2);
        for(int i=1;i<=n;++i) cin>>a[i];
        ll ans=0;
        for(int i=1;i<=n+1;++i) ans+=abs(a[i]-a[i-1]);
        for(int i=1;i<=n;++i) {
            if(a[i]>=a[i-1] && a[i]>=a[i+1]) ans-=a[i]-max(a[i-1],a[i+1]);
        }
        cout<<ans<<endl;
    }
}