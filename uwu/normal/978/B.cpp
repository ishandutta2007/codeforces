#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    int ans=0, cnt=-2;
    for (int i=0;i<n;++i){
        if (s[i]=='x') cnt++;
        else ans+=max(cnt,0), cnt=-2;
    }
    ans+=max(cnt,0);
    cout << max(ans,0) << '\n';
}