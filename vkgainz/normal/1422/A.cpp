#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a+b+c>=2*max({a,b,c})) cout << 1 << endl;
        else cout << max({a,b,c})*2-(a+b+c)+1 << endl;
    }
}