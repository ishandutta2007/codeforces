#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

map<char,int> m;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        m.clear();
        int n; cin >> n;
        for (int i=1;i<=n;++i){
            string uwu; cin >> uwu;
            for (char x:uwu) m[x]++;
        }
        bool flag=1;
        for (auto x:m){
            if (x.second%n!=0){
                flag=0;
            }
        }
        cout << (flag?"YES":"NO") << '\n';
    }
}