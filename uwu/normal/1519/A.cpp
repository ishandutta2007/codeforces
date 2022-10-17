#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int r, b, d; cin >> r >> b >> d;
        if (b>r) swap(r,b);
        int m=(r+b-1)/b;
        cout << (m-1<=d?"YES":"NO") << '\n';
    }
}