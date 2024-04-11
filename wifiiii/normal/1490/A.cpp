#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        int ans=0;
        for(int i=1;i<n;++i) {
            int mx=max(a[i],a[i-1]),mn=min(a[i],a[i-1]);
            while(mn*2<mx) {
                mn*=2;
                ++ans;
            }
        }
        cout<<ans<<endl;
    }
}