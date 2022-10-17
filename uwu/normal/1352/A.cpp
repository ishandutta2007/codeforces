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
        int uwu=1;
        vector<int> ans;
        while (uwu<=n){
            if (((n%(10*uwu))-n%uwu)!=0) ans.push_back(((n%(10*uwu))-n%uwu));
            uwu*=10;
        }
        cout << ans.size() << '\n';
        for (int x:ans){
            cout << x << " ";
        }
        cout << '\n';
    }
}