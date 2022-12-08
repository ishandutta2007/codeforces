#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a.begin(), a.end());
        ll g=0;
        for(int i=1;i<a.size();++i) {
            g=gcd(g, a[i]-a[i-1]);
        }
        int ok=0;
        for(int i=0;i<n;++i) {
            if(abs(k-a[i])%g==0) {
                ok=1;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}