#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

ll arr[MAXN*2];

ll getval(ll l, ll r){
    return (r*(r+1))/2-(l*(l-1))/2;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    ll n,x; cin >> n >> x;
    ll ans=0;
    ll days=0; ll hugs=0;
    for (int i=1;i<=n;++i){
        cin >> arr[i]; arr[i+n]=arr[i];
        ans=max(ans,arr[i]);
        days+=arr[i]; hugs+=getval(1,arr[i]);
    }
    if (days==x){
        cout << hugs << '\n';
        return 0;
    }

    deque<ll> q;
    days=hugs=0;
    int idx=n; ll prev;
    while (days<=x){
        q.push_front(arr[idx]);
        days+=arr[idx];
        hugs+=getval(1,arr[idx]);
        idx--;
    }
    prev=q.front(); days-=prev; hugs-=getval(1,prev); q.pop_front();

    ll temp;
    for (int i=n+1;i<=2*n;++i){
        q.push_back(arr[i]); days+=arr[i]; hugs+=getval(1,arr[i]);
        while (days>x){
            prev=q.front(); days-=prev; hugs-=getval(1,prev); q.pop_front();
        }
        temp=getval(prev-(x-days)+1,prev);
        ans=max(ans,hugs+temp);
    }
    cout << ans << '\n';

}