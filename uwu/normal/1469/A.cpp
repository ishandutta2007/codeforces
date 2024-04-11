#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        bool ans=1;
        if (s.size()%2==1) ans=0;
        if (s[0]==')'||s[s.size()-1]=='(') ans=0;
        cout << (ans?"yes":"no") << '\n';
    }
}