#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, s, k;
    cin >> t >> s >> k;
    k -= t;
    if (k == 1 || k < 0){
        cout << "NO";
        return 0;
    }
    if (k % s == 0 || k % s == 1){
        cout << "YES";
        return 0;
    }
    cout << "NO";
}