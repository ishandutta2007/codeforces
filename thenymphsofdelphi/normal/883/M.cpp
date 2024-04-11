#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, n, m, ans;
    cin >> a >> b >> c >> d;
    n = abs(a - c);
    m = abs(b - d);
    if (n == 0){
        n++;
    }
    if (m == 0){
        m++;
    }
    ans = n * 2 + m * 2 + 4;
    cout << ans;
}