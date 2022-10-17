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
        string uwu; cin >> uwu;
        int ones=0,zeroes=0;
        for (int i=0;i<uwu.size();++i){
            if (uwu[i]=='0') zeroes++;
            else ones++;
        }
        int ans=min(zeroes,ones);
        int c0=zeroes,c1=ones,cnt=0;
        for (int i=0;i<uwu.size();++i){ //11000
            if (uwu[i]=='0') cnt++;
            if (uwu[i]=='1') c1--;
            ans=min(ans,cnt+c1);
        }
        c0=zeroes,c1=ones,cnt=0;
        for (int i=0;i<uwu.size();++i){ //00011
            if (uwu[i]=='1') cnt++;
            if (uwu[i]=='0') c0--;
            ans=min(ans,cnt+c0);
        }
        cout << ans << '\n';
    }
}