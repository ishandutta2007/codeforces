#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,p; cin >> n >> p;
    vector<int> arr(n+1);
    for (int i=1;i<=n;++i) cin >> arr[i];
    sort(arr.begin(),arr.end());
    int uwu=1;
    for (int i=n;i>=1;--i) uwu=max(uwu,arr[i]-i+1);
    int ans=1e5;
    for (int i=1;i<=n-p+1;++i){
        ans=min(ans,arr[i+p-1]-uwu-i+1);
    }
    if (ans<0) ans=0;
    cout << ans << '\n';
    for (int i=0;i<ans;++i) cout << uwu+i << " ";
    cout << '\n';
}