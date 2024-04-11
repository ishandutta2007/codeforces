#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

ll value(ll x,ll y){
    return (((x+y)*(x+y-1))/2)-y+1;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        ll x=x2-x1,y=y2-y1,cnt=min(x,y);
        ll ans=(cnt*(cnt+1))+cnt*(abs(x-y)-1);
        if (x2<x1||y2<y1) cout << 0 << '\n';
        else cout << ans+1 << '\n';

    }
}