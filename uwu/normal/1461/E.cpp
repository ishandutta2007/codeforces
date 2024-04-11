#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll k, l, r, t, x, y; cin >> k >> l >> r >> t >> x >> y;
    if (x<y){
        ll tmp=(k-l)/x;
        k-=tmp*x, t-=tmp;
        for (int i=1;i<=x;++i){
            if (t<=0){ cout << "YES" << '\n'; return 0; }
            if (r-y<k){ cout << "NO" << '\n'; return 0; }
            tmp=(r-y)/(y-x)-(k)/(y-x)+1;
            k+=tmp*(y-x), t-=tmp;
            // cout << k << " ";
            if (t<=0){ cout << "YES" << '\n'; return 0; }
            tmp=(k-l)/x;
            k-=tmp*x, t-=tmp;
        }
        cout << "YES" << '\n';
    }
    if (x==y){
        if (k-x>=l||k+y<=r) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    if (x>y){
        ll temp=((r-y)/k)*k+k%x;
        if (temp<l){
            cout << ((k-l)/x>=t?"YES":"NO") << '\n';
            return 0;
        }
        else if (temp<=k){
            t-=(k-temp)/x;
            k=temp;
        }
        cout << ((k-l)/(x-y)>=t?"YES":"NO") << '\n';
    }
}