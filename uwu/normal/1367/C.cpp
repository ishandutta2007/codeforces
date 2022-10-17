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
        int n,k; cin >> n >> k;
        vector<int> arr; arr.push_back(0-k);
        char temp;
        for (int i=1;i<=n;++i){
            cin >> temp;
            if (temp=='1') arr.push_back(i);
        }
        ll ans=0;
        arr.push_back(n+1+k);
        for (int i=0;i<arr.size()-1;++i){
            if (arr[i+1]-arr[i]-1>=2*k+1){
                ans+=(arr[i+1]-arr[i]-1-k)/(k+1);
            }
        }
        cout << ans << '\n';
    }
}