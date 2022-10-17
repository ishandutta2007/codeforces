#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=110;

int n,m,ans;
char a;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n >> m;
        ans=0;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                cin >> a;
                if (j==m&&a=='R') ans++;
                if (i==n&&a=='D') ans++;
            }
        }
        cout << ans << '\n';
    }
}