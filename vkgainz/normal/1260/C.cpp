#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;
ll r,b,k;
void solve(){
    ll gcd = __gcd(r,b);
    r/=gcd;
    b/=gcd;
    if(r>b){
        swap(r,b);
    }
    if((k-1)*r+1<b){
        cout << "REBEL" << endl;
    }
    else{
        cout << "OBEY" << endl;
    }
}
int main(){
    cin >> T;
    while(T--){
        cin >> r >> b >> k;
        solve();
    }
}