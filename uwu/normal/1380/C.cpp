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
        int n; ll x; cin >> n >> x;
        priority_queue<ll> pq;
        for (int i=1,a;i<=n;++i) cin >> a, pq.push(a);
        ll cnt=0,ans=0;
        while (!pq.empty()){
            ll a=pq.top(); pq.pop();
            cnt++;
            if (a*cnt>=x) ans++,cnt=0;
        }
        cout << ans << '\n';
    }
}