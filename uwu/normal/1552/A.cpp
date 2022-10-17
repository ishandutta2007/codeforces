#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        string t=s;
        sort(t.begin(),t.end());
        int ans=0;
        for (int i=0;i<n;++i){
            if (s[i]!=t[i]) ans++;
        }
        cout << ans << '\n';
    }
}