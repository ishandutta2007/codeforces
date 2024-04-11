#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a + 4);
    bool t = 0, s = 0;
    if (a[0] + a[1] > a[2]){
        t = 1;
    }
    if (a[0] + a[1] == a[2]){
        s = 1;
    }
    if (a[1] + a[2] > a[3]){
        t = 1;
    }
    if (a[1] + a[2] == a[3]){
        s = 1;
    }
    if (t){
        cout << "TRIANGLE";
        return 0;
    }
    if (s){
        cout << "SEGMENT";
        return 0;
    }
    cout << "IMPOSSIBLE";
}