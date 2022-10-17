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
        int odd=0,even=0; // index
        for (int i=0;i<n;++i){
            cin >> arr[i];
            if (arr[i]%2==1&&i%2==0) even++;
            if (arr[i]%2==0&&i%2==1) odd++;
        } 
        if (odd!=even) cout << -1 << '\n';
        else cout << odd << '\n';
    }
}