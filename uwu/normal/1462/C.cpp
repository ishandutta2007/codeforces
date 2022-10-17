#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        if (n>45){ cout << -1 << '\n'; continue; }
        ll ans=LLONG_MAX;
        for (int i=1;i<(1<<9);++i){
            int tot=0; string curr="";
            for (int j=0;j<9;++j){
                if (1&(i>>j)) tot+=j+1, curr+=j+1+'0';
            }
            if (tot==n) sort(curr.begin(),curr.end()), ans=min(ans,stoll(curr));
        }
        cout << ans << '\n';
    }
}