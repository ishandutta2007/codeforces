#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        ll ans=0;
        vector<ll> b(n+5);
        for(int i=0;i<n;++i) {
            if(i) b[i]+=b[i-1];
            if(b[i]) {
                if(b[i]<a[i]) {
                    b[min(n,i+a[i]+1)]--;
                    b[min(n,i+a[i]-b[i]+1)]++;
                    a[i]-=b[i];
                } else {
                    b[min(n,i+a[i]+1)]--;
                    b[i+2]++;
                    ll res=b[i]-a[i]+1;
                    b[i+1]+=res;
                    b[i+2]-=res;
                    a[i]=1;
                }
            }
            if(a[i]==1) continue;
            ans+=a[i]-1;
            b[i+2]++;
            b[min(n,i+a[i]+1)]--;
            a[i]=1;
        }
        cout<<ans<<endl;
    }
}