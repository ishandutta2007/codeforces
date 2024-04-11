#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        if (__builtin_popcount(n)==1&&n!=1){
            int lg=31-__builtin_clz(n);
            cout << (lg%2==0?"Alice":"Bob") << '\n';
        }
        else{
            cout << (n%2==0?"Alice":"Bob") << '\n';
        }
    }
}