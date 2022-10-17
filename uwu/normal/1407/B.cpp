#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int arr[n+1],ans[n+1],best=0,idx,gcd;
        for (int i=1;i<=n;++i){
            cin >> arr[i];
            if (arr[i]>best) best=arr[i], idx=i;
        }
        gcd=best, arr[idx]=-1; ans[1]=best;
        for (int i=2;i<=n;++i){
            best=0; idx=0;
            for (int j=1;j<=n;++j){
                if (arr[j]==-1) continue;
                if (__gcd(gcd,arr[j])>best) best=__gcd(gcd,arr[j]), idx=j;
            }
            gcd=__gcd(gcd,arr[idx]); ans[i]=arr[idx], arr[idx]=-1;
        }
        for (int i=1;i<=n;++i) cout << ans[i] << " ";
        cout << '\n';
    }
}