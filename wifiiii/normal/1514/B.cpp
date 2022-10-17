#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=1e9+7;
ll fpow(ll a,ll b){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r%mod;}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        cout<<fpow(n,k)<<'\n';
    }
}