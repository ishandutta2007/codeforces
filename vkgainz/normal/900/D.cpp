#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;
ll get(int i){
    if(i==0) return 1;
    ll x = get(i/2);
    if(i%2==1){
        return ((x*x%mod*2)%mod+mod)%mod;
    }
    else{
        return ((x*x%mod)+mod)%mod;
    }
}
map<int, ll> divget;
set<int> divisors;
map<int,int> num;
void update(int i,int x){
    for(auto &it : divisors)
        if(it%i==0) num[it]+=x;
}
int main(){
    int x,y; cin >> x >> y;
    if(y%x!=0){
        cout << 0 << endl;
        return 0 ;
    }
    y/=x;
    for(int i=1;i<=sqrt(y);i++){
        if(y%i==0){
            divget[i] = get(y/i-1);
            divget[y/i] = get(i-1);
            divisors.insert(i);
            divisors.insert(y/i);
        }
    }
    ll ans = divget[1];
    update(1,1);
    for(int i : divisors){
        if(y%i==0 && i!=1){
            ans+=divget[i]*1LL*-num[i];
            ans%=mod;
            update(i,-num[i]);
        }
    }
    if(ans<0) ans+=mod;
    cout << ans << endl;
    
}