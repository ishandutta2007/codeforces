#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3001;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, tot=0; cin >> n;
        for (int i=1;i<=n;++i) cin >> arr[i], tot+=arr[i];
        for (int i=n;i>=1;--i){
            if (tot%i!=0) continue;
            bool can=1;
            int curr=0;
            for (int j=1;j<=n;++j){
                curr+=arr[j];
                if (curr==tot/i) curr=0;
                if (curr>tot/i) can=0;
            }
            if (can){ cout << n-i << '\n'; break; }
        }
    }
}