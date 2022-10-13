#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        if(n<k) cout << (k-n) << endl;
        else cout << ((n-k%2%2)+2)%2 << endl;
    }
}