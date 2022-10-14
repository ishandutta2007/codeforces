#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << min(a, min(b - 1, c -2))* 3 + 3;
}