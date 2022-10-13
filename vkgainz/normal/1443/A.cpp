#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i=2*n+2;i<=4*n;i+=2) cout << i << " ";
        cout << endl;
    }
}