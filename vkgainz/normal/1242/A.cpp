#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_prime(ll x){
    for(ll i=2;i<=sqrt(x);i++){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    ll n; cin >> n;
    if(is_prime(n)){
        cout << n << endl;
        return 0;
    }
    for(ll i=2;i<=sqrt(n);i++){
        ll temp= n;
        while(temp%i==0){
            temp/=i;
        }
        if(temp==1){
            if(is_prime(i)){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
}