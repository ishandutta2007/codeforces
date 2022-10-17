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
        vector<int> a(n);
        for(int i=0;i<n;++i) cin >> a[i];
        sort(a.begin(), a.end());
        ll ans=0;
        int l=0,r=n-1;
        ll ls=0,rs=0;
        for(int i=0;i<n;++i) rs+=a[i];
        for(int i=0;i<n;++i) {
            rs-=a[i];
            ans+=rs-1ll*r*a[i]+1ll*l*a[i]-ls;
            ++l,--r;
            ls+=a[i];
        }
        ans=ans/2-a.back();
        cout<<-ans<<endl;
    }
}