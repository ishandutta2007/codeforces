#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    set<ll> s;
    for(ll i=1;i*i*i<=1e12;++i) s.insert(i*i*i);
    while(t--) {
        ll n;
        cin>>n;
        int ok=0;
        for(ll i:s) {
            if(i>n) break;
            if(s.find(n-i)!=s.end()) {
                ok=1;
                break;
            }
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
}