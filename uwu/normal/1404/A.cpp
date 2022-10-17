#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=0;

bool solve(){
    int n,k; cin >> n >> k;
    string s; cin >> s; s=" "+s;
    for (int i=k+1;i<=n;++i){
        if (s[i]=='?') s[i]=s[i-k];
        else if (s[i-k]!='?'&&s[i]!=s[i-k]) return 0;
    }
    for (int i=n-k;i>=1;--i){
        if (s[i]=='?') s[i]=s[i+k];
        else if (s[i+k]!='?'&&s[i]!=s[i+k]) return 0;
    }
    int cnt0=0,cnt1=0,cnt2=0;
    for (int i=1;i<=k;++i){
        if (s[i]=='?') cnt2++;
        if (s[i]=='1') cnt1++;
        if (s[i]=='0') cnt0++;
    }
    return min(cnt0,cnt1)+cnt2>=max(cnt0,cnt1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cout << (solve()?"YES":"NO") << '\n';
    }
}