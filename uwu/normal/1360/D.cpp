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
        int n,k; cin >> n >> k;
        int ans=0x3f3f3f3f;
        for (int i=1;i<=sqrt(n);++i){
            if (i<=k&&n%i==0){
                ans=min(ans,n/i);
                if ((n/i)<=k) ans=min(ans,i);
            }
        }
        cout << ans << '\n';
    }
}