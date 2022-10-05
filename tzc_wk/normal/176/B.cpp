#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
typedef long long ll;
const int N = 1000 + 10, mod = 1000000000 + 7;
char s[N], t[N];
int k, n;
ll f[2][2], ans;
void init(){
    scanf("%s%s%d", s, t, &k);
    n = strlen(s);
}
void work(){
    f[0][0] = 1;
    rep(i, 1, k){
        f[i&1][0] = (f[i&1^1][1] * (n - 1)) % mod;
        f[i&1][1] = (f[i&1^1][0] + f[i&1^1][1] * (n - 2)) % mod;
    }
    int ok;
    rep(i, 0, (n - 1)){
        ok = 1;
        rep(j, 0, (n - 1))
            if(s[(j+i)%n] != t[j]){
                ok = 0;
                break;
            }
        if(ok)
            if(i == 0) ans += f[k&1][0];
            else ans += f[k&1][1];
        ans %= mod;
    }
    cout<<ans<<endl;
}

int main(){
    init();
    work();
    return 0;
}