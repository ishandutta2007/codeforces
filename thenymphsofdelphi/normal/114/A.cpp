#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int k, l, t, i = 0;
    cin >> k >> l;
    t = k;
    while (t < l){
        t = t * k;
        i++;
    }
    if (t == l){
        cout << "YES\n" << i;
    }
    else{
        cout << "NO";
    }
}