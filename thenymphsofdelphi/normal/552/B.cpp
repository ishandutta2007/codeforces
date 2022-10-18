#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, ans = 0, dg = 1, t = 9;
    cin >> n;
    while (n > 0){
        ans += t * dg;
        n -= t;
        t *= 10;
        dg++;
    }
    dg--;
    ans += n * dg;
    cout << ans;
}