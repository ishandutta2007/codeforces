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
        string s, w=" 2020"; cin >> s; s=" "+s;
        int pre=0, suf=0;
        for (int i=1;i<=4;++i){
            if (s[i]==w[i]) pre++;
            else break;
        }
        for (int i=4;i>=1;--i){
            if (s[n-4+i]==w[i]) suf++;
            else break;
        }
        cout << (pre+suf>=4?"YES":"NO") << '\n';
    }
}