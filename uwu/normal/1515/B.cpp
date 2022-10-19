#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

bool psq(int n){
    double x=round(sqrt(n));
    return abs(x*x-n)<1e-9;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        if (n%2==1) cout << "NO" << '\n';
        else{
            n/=2;
            cout << (psq(n)||(n%2==0&&psq(n/2))?"YES":"NO") << '\n';
        }
    }
}