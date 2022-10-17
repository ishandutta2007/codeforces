#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll x,y,a,b; cin >> x >> y >> a >> b;
        b=min(a*2,b);
        ll total=0;
        total+=b*min(x,y);
        total+=a*(max(x,y)-min(x,y));
        cout << total << '\n';
    }
}