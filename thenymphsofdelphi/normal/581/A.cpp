#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, x;
    cin >> a >> b;
    x = min(a, b);
    cout << x << " ";
    a -= x;
    b -= x;
    cout << (a + b) / 2;
}