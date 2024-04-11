#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        string ans1, ans2;
        for (char x:s){
            if (x=='b') ans2+=x;
            else ans1+=x;
        }
        cout << ans2 << ans1 << '\n';
    }
}