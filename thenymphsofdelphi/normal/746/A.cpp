#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    a /= 1;
    b /= 2;
    c /= 4;
    cout << 7 * min(min(a, b), c);
}