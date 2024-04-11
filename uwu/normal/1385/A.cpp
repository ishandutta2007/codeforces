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
        int a,b,c; cin >> a >> b >> c;
        if (b>a) swap(a,b);
        if (c>a) swap(a,c);
        if (c>b) swap(c,b);
        if (a!=b) cout << "NO" << '\n';
        else cout << "YES" << '\n' << a << " " << c << " " << 1 << '\n';
    }
}