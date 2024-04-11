#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
vector<ll> f,s;
int n,k;
ll get(int e1,int e2,int numBetween){
    if(e1==0 && e2==0){
        if(numBetween==0) return 1;
        ll prod= k;
        for(int i=1;i<=numBetween-1;i++){
            prod*=(ll)(k-1);
            prod%=mod;
            if(prod<0) prod+=mod;
        }
        return prod;
    }
    if(e1==0 || e2==0){
        if(numBetween==0) return 1;
        ll prod = (k-1);
        for(int i=1;i<=numBetween-1;i++){
            prod*=(ll)(k-1);
            prod%= mod;
            if(prod<0) prod+=mod;
        }
        return prod;
    }
    if(numBetween==0){
        return e1!=e2;
    }
    vector<ll> dpeq;
    vector<ll> dpdiff;
    dpeq.assign(numBetween+5,0LL);
    dpdiff.assign(numBetween+5,0LL);
    if(e1==e2)
        dpeq[0] = 1;
    else
        dpdiff[0] = 1;
    for(int i=1;i<=numBetween;i++){
        dpeq[i] = dpdiff[i-1];
        dpdiff[i] =(ll) dpdiff[i-1]*(k-2);
        dpdiff[i]+=(ll) dpeq[i-1]*(k-1);
        dpeq[i]%=mod;
        dpdiff[i]%=mod;
        if(dpeq[i]<0) dpeq[i]+=mod;
        if(dpdiff[i]<0) dpdiff[i]+=mod;
    }
    return dpdiff[numBetween];
}
ll sim(vector<ll> &t){
    int i = 0;
    int e1 =0;
    int e2 = 0;
    ll ans = 1;
    while(i<t.size()-1){
        int j= i+1;
        e1 = t[i];
        while(j<t.size() && t[j]==-1){
            j++;
        }
        e2 = t[j];
        ans*=get(e1,e2,j-i-1);
        ans%=mod;
        if(ans<0) ans+=mod;
        i = j;

    }
    return ans;
       
}
int main(){
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    f.push_back(0);
    s.push_back(0);
    for(int i=0;i<n;i++){
        if(i%2) f.push_back(a[i]);
        else s.push_back(a[i]);
    }
    f.push_back(0);
    s.push_back(0);
    ll x = sim(f);
    ll y = sim(s);
    ll ans = x*y%mod;
    if(ans<0) ans+=mod;
    cout << ans << endl;
}