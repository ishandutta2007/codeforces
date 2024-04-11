#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll tot=1,bad=1;
    for (int i=1;i<=n;++i){
        tot*=i; tot%=mod;
        if (i!=n) bad*=2; bad%=mod;
    }
    cout << (tot-bad+mod)%mod << '\n';
}