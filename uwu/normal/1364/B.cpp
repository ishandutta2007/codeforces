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
        vector<int> ans;
        for (int i=1;i<=n;++i) cin >> arr[i];
        ans.push_back(arr[1]);
        for (int i=2;i<=n-1;++i){
            if (arr[i]>arr[i-1]&&arr[i]>arr[i+1]) ans.push_back(arr[i]);
            if (arr[i]<arr[i-1]&&arr[i]<arr[i+1]) ans.push_back(arr[i]);
        }
        ans.push_back(arr[n]);
        cout << ans.size() << '\n';
        for (int i=0;i<ans.size();++i) cout << ans[i] << " ";
        cout << '\n';
    }
}