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
        int n; cin >> n;
        vector<int> arr(n+1);
        for (int i=1;i<=n;++i) cin >> arr[i];
        sort(arr.begin(),arr.end());
        int ans=0;
        for (int i=1;i<=n;++i){
            if (arr[i]<=i) ans=max(ans,i);
        }
        cout << ans+1 << '\n';
    }
}