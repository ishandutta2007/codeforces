#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> pf;
void get(ll x){
    ll t = x;
    for(int i=2;i<=sqrt(t);i++){
        if(t%i==0){
            ll fac = 0;
            while(t%i==0){
                fac++;
                t/=i;
            }
            pf[i] = max(pf[i],fac);
        }
    }
    if(t>1) pf[t] = max(pf[t],1LL);
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> d;
        pf.clear();
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            d.insert(x);
            get(x);
        }
        ll prod = 1;
        ll minP = 10000000;
        ll numNeed = 1;
        int num = 0;
        for(auto &it : pf){
            prod*=(ll) pow(it.first,it.second);
            minP= min(minP,it.first);
            numNeed*=(it.second+1);
            num++;
        }
        if(d.find(prod)!=d.end()){
            if(num==1 && numNeed==n+1){
                cout << prod*minP << endl;
            }
            else
                cout << -1 << endl;
        }
        else{
            numNeed-=2;
            if(numNeed!=n){
                cout << -1 << endl;
            }
            else{
                cout << prod << endl;
            }
        }



    }
}