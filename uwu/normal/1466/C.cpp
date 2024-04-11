#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        int n=s.size();
        s=" "+s;
        int cnt=0;
        for (int i=2;i<=n;++i){
            if (s[i]==s[i-1]||s[i]==s[i-2]) s[i]=' ', cnt++;
        }
        cout << cnt << '\n';
    }
}