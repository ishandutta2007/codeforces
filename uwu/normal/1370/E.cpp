#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    string a; cin >> a;
    string b; cin >> b;
    int ca=0,cb=0;
    int as=0,bs=0;
    for (int i=0;i<n;++i){
        ca+=a[i]-'0'; cb+=b[i]-'0';
        if (a[i]=='1'&&b[i]=='0'){
            as++;
            if (bs!=0) bs--;
        }
        if (a[i]=='0'&&b[i]=='1'){
            bs++;
            if (as!=0) as--;
        }
    }
    cout << ((ca==cb)?as+bs:-1) << '\n';
}