#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--) {
        int l,r;
        cin >> l >> r;
        if(2*l<r+1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}