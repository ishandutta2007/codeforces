#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        string s, t; cin >> s >> t;
        int n=s.size(), m=t.size();
        bool ans=0;
        for (int i=0;i<n;++i){
            for (int j=i;j<n;++j){
                string tmp=s.substr(i,j-i+1);
                for (int k=j;k>=0;--k){
                    if (k!=j) tmp+=s[k];
                    if (tmp.size()==t.size()&&tmp==t) ans=1;
                }
            }
        }
        cout << (ans?"YES":"NO") << '\n';
    }
}