#include<bits/stdc++.h>
using namespace std;

int main(){
    int l, r, a, ans;
    cin >> l >> r >> a;
    ans = min(l, r);
    int dif = abs(l - r);
    if (a <= dif){
        cout << (ans + a) * 2;
        return 0;
    }
    ans = max(l, r);
    a -= dif;
    cout << (ans + a / 2) * 2;
}