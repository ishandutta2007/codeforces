#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxM=2e5, M=998244353;
int n, m, a, b[mxM+1];

ll exp(ll b, int p) {
    ll r=1;
    while(p) {
        if(p&1)
            r=r*b%M;
        b=b*b%M;
        p/=2;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> a;
    ll ans=1, c;
    for(int i=1; i<=m; ++i) {
        cin >> b[i];
        c=exp(a, b[i]-b[i-1]);
        ans=c*(c+1)/2%M*ans%M;
    }
    cout << ans*exp(a, n-2*b[m])%M;
}