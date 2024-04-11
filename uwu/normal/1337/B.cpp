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
        int x,n,m;
        cin >> x >> n >> m;
        while (n--){
            if (x<=20) break;
            x=floor(x/2);
            x+=10;
        }
        while (m--){
            x-=10;
        }
        if (x<=0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}