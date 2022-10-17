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
        uwu='0'+uwu;
        string ans;
        for (int i=1;i<=n;++i){
            if (uwu[i]=='1') break;
            ans+='0';
        }
        for (int i=1;i<=n;++i){
            if (uwu[i]=='0'&&uwu[i-1]=='1'){ ans+='0'; break; }
        }
        for (int i=n;i>=1;--i){
            if (uwu[i]=='0') break;
            ans+='1';
        }
        cout << ans << '\n';
    }
}