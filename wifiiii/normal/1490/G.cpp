#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<ll> a(n),s(n+1);
        ll sum=0,mx=0;
        for(int i=0;i<n;++i) cin>>a[i],sum+=a[i],mx=max(mx,sum),s[i+1]=s[i]+a[i];
        for(int i=1;i<=n;++i) s[i]=max(s[i],s[i-1]);
        while(m--) {
            ll x;
            cin>>x;
            if(mx<x && sum<=0) {
                cout<<-1<<' ';
                continue;
            }
            if(mx>=x) {
                cout<<lower_bound(s.begin(),s.end(),x)-s.begin()-1<<' ';
            } else {
                ll p=(x-mx-1)/sum+1;
                x-=p*sum;
                assert(x<=mx);
                cout<<lower_bound(s.begin(),s.end(),x)-s.begin()+p*n-1<<' ';
            }
        }
        cout<<'\n';
    }
}