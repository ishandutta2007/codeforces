#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> ans;
int main(){
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i*i<=n;i++) if (n%i==0){
        k--;
        if (!k) {
            cout<<i;
            return 0;
        }
        if (i*i!=n) ans.push_back(n/i);
    }
    reverse(ans.begin(),ans.end());
    if (k>ans.size()) cout<<-1;
    else cout<<ans[k-1];
}