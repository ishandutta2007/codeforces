#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;
ll pow2(int n){
    ll prod = 1;
    for(int i=1;i<=n-1;i++){
        prod*=2;
        prod%=mod;
    }
    return prod;
}
ll fac(int n){
    ll prod = 1;
    for(int i=1;i<=n;i++){
        prod = prod*i;
        prod%=mod;
    }
    return prod;
}
int main(){
    int n;
    cin >> n;
    ll a = fac(n);
    ll b = pow2(n);
    a-=b;
    a%=mod;
    if(a<0) a+=mod;
    cout << a << endl;
}