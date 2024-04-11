#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    vector<ll> b;
    for(int i=1;i<n;++i) {
        if(a[i]==a[i-1]) b.push_back(0);
        else b.push_back( (a[i]-a[i-1]-1)/x );
    }
    sort(b.begin(),b.end());
    for(ll i:b) {
        k-=i;
        if(k<0) break;
        --n;
    }
    cout<<n<<endl;
}