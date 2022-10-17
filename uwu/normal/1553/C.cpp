#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int lim=1<<10;
int val[1<<10];

int calc(int mask){
    int ca=0, cb=0, la=5, lb=5;
    for (int i=0;i<10;++i){
        if (i%2==0){
            la--;
            if (1&(mask>>i)) ca++;
        }
        else{
            lb--;
            if (1&(mask>>i)) cb++;
        }
        if (ca>cb+lb) return i+1;
        if (cb>ca+la) return i+1;
    }
    return 10;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i=0;i<lim;++i) val[i]=calc(i);
    while (t--){
        string s; cin >> s;
        int ans=10;
        for (int i=0;i<lim;++i){
            bool can=1;
            for (int j=0;j<10;++j){
                if (s[j]=='?') continue;
                if (s[j]=='1'&&!(1&(i>>j))) can=0;
                if (s[j]=='0'&&(1&(i>>j))) can=0;
            }
            if (can) ans=min(ans,val[i]);
        }
        cout << ans << '\n';
    }
}