#include <bits/stdc++.h>
 
using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=501;
 
int arr[MAXN];
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, x; cin >> n >> x;
        ms(arr,0);
        int ans=0;
        for (int i=1;i<=n;++i){
            cin >> arr[i];
            if (arr[i]<arr[i-1]&&arr[i]<x){ continue; }
            if (arr[i]<arr[i-1]){
                for (int j=1;j<=i;++j){
                    if (arr[j]>x) swap(x,arr[j]), ans++;
                }
            }
        }
        for (int i=1;i<=n;++i) if (arr[i]<arr[i-1]) ans=-1;
        cout << ans << '\n';
    }
}

// 4 295
// 289 448 390 431