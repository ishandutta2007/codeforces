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
        string uwu; cin >> uwu;
        string ans; ans+=uwu[0];
        for (int i=1;i<uwu.size()-1;i+=2){
            ans+=uwu[i];
        }
        ans+=uwu.back();
        cout << ans << '\n';
    }
}