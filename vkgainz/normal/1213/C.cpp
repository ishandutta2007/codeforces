#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n,m;
    cin >> n >> m;
    int x = (m%10);
    int a[10];
    for(int i=0;i<10;i++){
        a[i] = (x*i)%10;
    }
    ll numIter = (n/m)/10;
    ll res = (n/m)%10;
    int sum = 0;
    for(int i=0;i<10;i++) sum+=a[i];
    ll ans = 0;
    ans = (ll) numIter*sum;
    for(int i=1;i<=res;i++){
        ans+=a[i];
    }
    cout << ans << endl;
}
int main(){
    int q;
    cin >> q;
    while(q--) solve();
}