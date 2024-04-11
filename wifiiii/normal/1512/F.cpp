#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,c;
        cin>>n>>c;
        vector<int> a(n),b(n);
        for(int i=0;i<n;++i) {
            cin>>a[i];
            if(i) a[i]=max(a[i],a[i-1]);
        }
        for(int i=0;i<n-1;++i) cin>>b[i];
        ll ans=1e18,cur=0,res=0;
        for(int i=0;i<n;++i) {
            ans=min(ans,cur+(c-res+a[i]-1)/a[i]);
            //i->i+1
            if(i+1<n) {
                ll used=(b[i]-res+a[i]-1)/a[i];
                cur+=used+1;
                res=res+a[i]*used-b[i];
                assert(res>=0);
            }
        }
        cout<<ans<<endl;
    }
}