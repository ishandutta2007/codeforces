#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const ll MN = 1e6+5, mod = 1e9+7;
ll n, m, i, x, l, hsh[MN], pw[MN]={1}, ok[MN], ans=1;
string s;

ll getHsh(ll x,ll y){
    ll r = hsh[y]-(hsh[x-1]*pw[y-x+1]%mod);
    if(r<0) r += mod;
    if(r>=mod) r -= mod;
    return r;
}

int main(){
    cin >> n >> m >> s;
    for(i=1;i<=s.size();i++){
        pw[i]=(pw[i-1]*131)%mod;
        hsh[i]=(hsh[i-1]*131+s[i-1]-'a'+1)%mod;
    }
    for(i=1;i<=m;i++){
        scanf("%lld",&x);
        if(i!=1){
            if(l+s.size()>x){
                int len = l+s.size()-x-1;
                if(getHsh(s.size()-len,s.size())!=getHsh(1,1+len)){
                    printf("0\n");
                    return 0;
                }
            }
        }
        ok[x] ++;
        ok[x+s.size()] --;
        l = x;
    }
    l = 0;
    for(i=1;i<=n;i++){
        l += ok[i];
        if(!l) ans=ans*26%mod;
    }
    printf("%lld\n",ans);
    return 0;
}