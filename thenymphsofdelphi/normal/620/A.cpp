#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d;
    e = abs(a - c);
    f = abs(b - d);
    cout << max(e, f);
}