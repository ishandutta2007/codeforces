#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
int main(){
    int n; cin >> n;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) {
        cin >> p[i];
        p[i] = p[i-1]^p[i];
    }
    map<int, int> l, r;
    for(int i=0;i<=n;i++) {
        if(i%2) ++l[p[i]];
        else ++r[p[i]];
    }
    ll ans = 0;
    for(auto &it : l) ans+=it.s*1LL*(it.s-1)/2;
    for(auto &it : r) ans+=it.s*1LL*(it.s-1)/2;
    cout << ans << endl;
}