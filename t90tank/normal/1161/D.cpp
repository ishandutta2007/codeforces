#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pll;

int f[3000];
int d[3000];
bool ok;

int getf(int v) {
    if (f[v] == v) return v;
    int fv = f[v];
    f[v] = getf(fv);
    d[v] ^= d[fv];
    return f[v];
}

void link(int a, int b, int c) {
    int fa = getf(a);
    int fb = getf(b);
    if (fa == fb) {
        ok &= ((d[a]^d[b]) == c);
        return;
    }
    d[fa] = (d[a]^d[b]^c);
    f[fa] = fb;
}

char s[2000];
int n;

int main() {
    scanf( "%s", s+1);
    n = strlen(s+1);
    ll ans = 0;
    ll mod = 998244353;
    for (int p = 1; p < n; ++p) {
        for (int i = 0; i <= n+p; ++i){
            f[i] = i;
            d[i] = 0;
        }
        ok = true;
        link(1,0,1);
        link(n+1,0,1);
        for (int i = 1; i < n+1-i; ++i)
            link(i,n+1-i,0);
        for (int i = 1; i < p+1-i; ++i)
            link(n+i,n+p+1-i,0);
        for (int i = 1; i <= n; ++i)
            if (s[n+1-i] != '?')
                if (i > p) link(n+1-i,0,s[n+1-i]-'0');
                else link(n+1-i,n+p+1-i,s[n+1-i]-'0');
        if (ok) {
            ll t = 0;
            for (int i = 0; i <= n+p; ++i)
                if (f[i] == i)
                    if (t == 0) t = 1;
                    else t = (t*2) % mod;
            ans = (ans+t) % mod;
        }
    }
    cout<<ans<<endl;
}