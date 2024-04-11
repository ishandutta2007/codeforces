#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll a,b,n; cin >> a >> b >> n;
        ll tempa=a, tempb=b;
        ll ans=min((n-a+b)/b,(n-b+a)/a);
        ll cnt=0;
        while (true){
            a+=b;
            cnt++;
            if (a>n){ ans=min(ans,cnt); break;}
            b+=a;
            cnt++;
            if (b>n){ ans=min(ans,cnt); break;}
        }
        cnt=0;
        a=tempa; b=tempb;
        while (true){
            b+=a;
            cnt++;
            if (b>n){ ans=min(ans,cnt); break;}
            a+=b;
            cnt++;
            if (a>n){ ans=min(ans,cnt); break;}
        }
        cout << ans << '\n';
    }
}