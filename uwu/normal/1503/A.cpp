#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        s=" "+s;
        int cnt1=0;
        for (int i=1;i<=n;++i){
            cnt1+=s[i]=='1';
        }
        if (cnt1%2||s[1]=='0'||s[n]=='0'){ cout << "NO" << '\n'; continue; }
        cout << "YES" << '\n';
        string a, b;
        int cnta=0, cntb=0, used=0;
        for (int i=1;i<=n;++i){
            if (s[i]=='1'){
                if (used>=cnt1/2){
                    cnta--, cntb--;
                    a+=')', b+=')';
                }
                else{
                    cnta++, cntb++;
                    a+='(', b+='(';
                }
                used++;
            }
            if (s[i]=='0'){
                if (cnta<=cntb){
                    cnta++, cntb--;
                    a+='(', b+=')';
                }
                else{
                    cnta--, cntb++;
                    a+=')', b+='(';
                }
            }
        }
        cout << a << '\n' << b << '\n';
    }
}