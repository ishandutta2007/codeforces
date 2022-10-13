#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t; cin >> t;
    while(t--){
        ll a,b,c;
        cin >> a >> b >> c;
        if(max(a,max(b,c))<=(a+b+c+1)/2){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}