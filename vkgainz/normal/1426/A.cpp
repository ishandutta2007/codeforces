#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        if(n<=2) cout << 1 << endl;
        else
        cout << (int)ceil((n-2)*1.0/x+1) << endl;
    }
}