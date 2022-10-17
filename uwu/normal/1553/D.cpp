#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

bool match(string s, string t){
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    int n=s.size(), m=t.size();
    int p=0, last=-1;
    for (int i=0;i<n;++i){
        if (s[i]==t[p]&&(i-last)%2){
            last=i, p++;
        }
        if (p==m) return 1;
    }
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        string s, t; cin >> s >> t;
        bool ans=match(s,t);
        cout << (ans?"Yes":"No") << '\n';
    }
}