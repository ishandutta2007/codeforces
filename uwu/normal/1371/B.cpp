#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n,r; cin >> n >> r;
        ll ans=0;
        if (r<n){
            ans+=(r*(r+1))/2;
        }
        else{
            ans+=((n-1)*n)/2;
            ans+=1;
        }
        cout << ans << '\n';
    }
}