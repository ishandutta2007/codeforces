#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, m;
    cin >> n >> m;
    if (n >= 27){
        cout << m;
        return 0;
    }
    int po = pow(2, n);
    cout << m % po;
}