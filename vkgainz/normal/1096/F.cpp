#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
ll seg[400000];
int n;
ll inverse(ll base, ll power){
    if(power==0) return 1;
    ll x = inverse(base,power/2);
    if(power%2==0){
        return ((x*x)%mod+mod)%mod;
    }
    else{
        return (((x*x)%mod*base)%mod+mod)%mod;
    }
}
struct fraction{
    ll a,b;
    fraction(ll x,ll y){
        a = x;
        b= y;
    }
    fraction add(fraction other){
        fraction ret = fraction(0,1);
        ret.a = (a*other.b+other.a*b);
        ret.b = (b*other.b);
        ret.reduce();
        return ret;
    }
    void reduce(){
        a%=mod; b%=mod;
        if(a<0) a+=mod; if (b<0) b+=mod;
        ll gcd = g(a,b);
        a/=gcd; b/=gcd;
        if(a<0) a+=mod; if (b<0) b+=mod;
    }
    ll g(ll a, ll b){
        if(b==0) return a;
        return g(b,a%b);
    }
};
void build(){
    for(int i=n-1;i>=1;i--) seg[i] = seg[2*i]+seg[2*i+1];
}
void update(int i){
    seg[i+=n]++;
    while(i>1){
        i/=2;
        seg[i] = seg[2*i]+seg[2*i+1];
    }
}
ll query(int l,int r){
    l+=n; r+=n;
    ll ret = 0;
    while(l<r){
        if(l%2) ret+=seg[l++];
        if(r%2) ret+=seg[r-1];
        l/=2; r/=2;
    }
    return ret;
}
int main(){
    cin >> n;
    //# of inversions, + number of 1s choose 2/2, + auxiliar
    int p[n];
    for(int i=0;i<n;i++){
        cin >> p[i];
        p[i]--;
    }
    int numn =0;
    vector<pair<int,int>> temp;
    for(int i=0;i<n;i++)
        if(p[i]==-2) numn++;
        else temp.push_back(make_pair(-p[i],i));
    sort(temp.begin(),temp.end());
    ll inv = 0;
    for(int i=0;i<temp.size();i++){
        inv+=query(0,temp[i].second);
        update(temp[i].second);
    }
    inv%=mod; if(inv<0) inv+=mod;
    ll numGreater[n];
    ll numLess[n];
    for(int i=0;i<temp.size();i++){
        numGreater[-temp[i].first] = n+temp[i].first-1-i;
        numLess[-temp[i].first] = -temp[i].first-(temp.size()-i-1);
    }
    ll num = 0;
    ll denom = 0;
    ll sum = 0;
    for(int i=0;i<n;i++){
        if(p[i]==-2){
            denom++;
            num+=(ll) sum;
        }
        else{
            sum+=numLess[p[i]];
            num+=(ll) denom*numGreater[p[i]];
        }
        num%=mod; if(num<0) num+=mod;
    }
    if(denom==0){
        cout << inv << endl;
    }
    else{
        fraction x = fraction(inv,1);
        fraction y = fraction(num,denom);
        ll r = denom*(denom-1); r%=mod; if(r<0) r+=mod;
        fraction z = fraction(r,4);
        x = x.add(y);
        x = x.add(z);
        ll mult = inverse(x.b,mod-2);
        x.a*=mult;
        x.a%=mod; if(x.a<0) x.a+=mod;
        cout << x.a << endl;
    }

}