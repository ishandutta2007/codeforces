#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=51;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        set<int> s;
        s.insert(0);
        int n; cin >> n;
        for (int i=1;i<=n;++i) cin >> arr[i];
        int cnt=0;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                int curr=abs(arr[j]-arr[i]);
                if (!s.count(curr)) cnt++, s.insert(curr);
            }
        }
        cout << cnt << '\n';
    }
}