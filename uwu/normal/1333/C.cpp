#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll a[200001],pre[200001];
map<ll,int> m;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    ll n; cin >> n; n++;
    for (int i=2;i<=n;++i){
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
    }
    ll ans=0;
    m[0]=1; int index=1;
    for (int i=2;i<=n;++i){
        if (m[pre[i]]>=index){
            //cout << i << " "  << (m[pre[i]]-index+1)*(n-i+1) << '\n';
            ans+=(m[pre[i]]-index+1)*(n-i+1);
            index=m[pre[i]]+1;
        }
        m[pre[i]]=i;
    }
    n--;
    cout << ((n*(n+1))/2)-ans << '\n';
}