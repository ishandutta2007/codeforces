#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
void exgcd(ll a,ll b,ll &d,ll &x,ll &y) {
    if(!b) {d=a;x=1;y=0;}
    else {exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}
ll inv(ll a,ll p) {
    ll d,x,y;
    exgcd(a,p,d,x,y);
    assert(d == 1);
    x%=p;
    if(x<0) x+=p;
    return x;
}
//ll mul(ll a,ll b,ll mod) {return (ll)(__int128(a)*b%mod);}
ll mul(ll a,ll b,ll mod) {ll tmp=(long double)a*b/mod;return ((a*b-tmp*mod)%mod+mod)%mod;}
// x = a_i (mod b_i)
ll excrt(vector<ll> a,vector<ll> b) {
    int k = a.size();
    ll c = a[0], p = b[0]; // c : ans, p : modulus
    for(int i=1;i<a.size();++i) {
        ll g,x,y;
        exgcd(p,b[i],g,x,y);
        ll r=(a[i]-c%b[i]+b[i])%b[i];
        if(r%g) return -1;
        x=mul(x,r/g,b[i]/g);
        c=c+x*p;
        p*=b[i]/g;
        c=(c%p+p)%p;
    }
    return c;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        vector<ll> b { 2, 3, 7, 11, 13, 17, 19, 23, 29 };
        vector<ll> a(b.size());
        for(ll i = 1; i <= 30; ++i) {
            cout << "? " << i << " " << 1293938646 + i << endl;
            ll r;
            cin >> r;
            for(int j = 0; j < b.size(); ++j) {
                if(r % b[j] == 0) {
                    // b[j] | (x + i) -> (x + i) = 0 (mod b[j])
                    a[j] = ((b[j] - i) % b[j] + b[j]) % b[j];
                }
            }
        }
        cout << "! " << excrt(a, b) << endl;
    }
}