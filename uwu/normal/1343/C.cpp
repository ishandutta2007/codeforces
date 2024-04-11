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
        vector<ll> arr(n);
        for (int i=0;i<n;++i){
            cin >> arr[i];
        }
        ll ans=0;
        ll curr=arr[0];
        for (int i=1;i<n;++i){
            if (curr*arr[i]<0){
                ans+=curr;
                curr=arr[i];
                continue;
            }
            curr=max(curr,arr[i]);
        }
        ans+=curr;
        cout << ans << '\n';
    }
}