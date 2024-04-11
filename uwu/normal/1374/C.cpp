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
        int n; cin >> n;
        string uwu; cin >> uwu;
        ll ans=0,curr=0;
        for (int i=0;i<n;++i){
            if (uwu[i]==')') curr++;
            else curr--;
            ans=max(ans,curr);
        }
        cout << ans << '\n';
    }
}