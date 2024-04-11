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
        vector<int> arr(n);
        for (int i=0;i<n;++i){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        int ans=0,cnt=0;
        for (int i=0;i<n;++i){
            cnt++;
            if (arr[i]<=cnt){
                cnt=0;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}