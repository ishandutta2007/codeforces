#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, w; cin >> n >> w;
        int tot=0;
        for (int i=1;i<=n;++i) cin >> arr[i];
        for (int i=1;i<=n;++i){
            tot+=arr[i];
            if (tot==w&&i!=n){
                tot-=arr[i];
                swap(arr[i],arr[i+1]);
                tot+=arr[i];
            }    
        }
        cout << (tot==w?"NO":"YES") << '\n';
        if (tot!=w){
            for (int i=1;i<=n;++i) cout << arr[i] << " ";
            cout << '\n';
        }
    }
}