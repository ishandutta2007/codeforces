#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> arr(n+1);
        for (int i=1;i<=n;++i) cin >> arr[i], arr[i]=abs(arr[i]);
        for (int i=2;i<=n;i+=2){
            arr[i]=-arr[i];
        }
        for (int i=1;i<=n;++i) cout << arr[i] << " ";
        cout << '\n';
    }
}