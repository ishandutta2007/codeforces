#include<bits/stdc++.h>
using namespace std;

int main(){
    long a, b, c;
    cin >> a >> b >> c;
    long d = 2 * (a + b), e = a + b + c, f = 2 * (b + c), g = 2 * (a + c);
    long h = min(d, e);
    h = min(h, f);
    h = min(h, g);
    cout << h;
}