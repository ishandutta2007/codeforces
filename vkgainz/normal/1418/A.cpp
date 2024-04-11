#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        ll x,y,k;
        cin >> x >> y >> k;
        ll a = ((y*k+x-2)/(x-1));
        ll add = k;
        ll left = (x-1)*a-y*k+1;
        ll b = ((k-left+x-2)/(x-1));
        cout << (a+b+add) << endl;
    }
}