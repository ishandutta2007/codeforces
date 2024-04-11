#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    int d = 1, abc = 0;
    for (int i = 1; i <= n; i++){
    	int td = abc * 3 % mod, tabc = (abc * 2 + d) % mod;
    	d = td;
    	abc = tabc;
    }
    cout << d;
}