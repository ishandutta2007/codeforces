#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int x = ceil(sqrt(n))-1;
        int y = ceil(n*1.0/(x+1)-1);
        cout << (x+y) << endl;
    }
}