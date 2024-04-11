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
        ll a,b,c; cin >> a >> b >> c;
        if (a<c) cout << 1 << " ";
        else cout << -1 << " ";
        if (a*b<=c) cout << -1 << '\n';
        else cout << b << '\n';
    }
}