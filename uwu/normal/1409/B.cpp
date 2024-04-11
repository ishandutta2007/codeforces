#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=0;

ll get(ll a, ll b, ll x, ll y, ll n){
    ll temp=min(a-x,n);
    a-=temp, n-=temp;
    temp=min(b-y,n);
    b-=temp, n-=temp;
    return a*b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll a,b,x,y,n; cin >> a >> b >> x >> y >> n;
        cout << min(get(a,b,x,y,n),get(b,a,y,x,n)) << '\n';
    }
}