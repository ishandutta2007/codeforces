#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
string s; ll ans, i, tot;

int main(){
    cin >> s;
    for(i=s.size()-1;i>=0;i--){
        if(s[i]=='a'){
            ans = (ans+tot)%mod;
            tot = (tot*2)%mod;
        }
        else{
            tot = (tot+1)%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}