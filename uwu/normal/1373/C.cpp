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
        string uwu; cin >> uwu;
        ll ans=uwu.size(),val=0;
        for (int i=0;i<uwu.size();++i){
            if (uwu[i]=='-') val--;
            else val++;
            if (val==-1) val++, ans+=i+1;
        }
        cout << ans << '\n';
    }
}