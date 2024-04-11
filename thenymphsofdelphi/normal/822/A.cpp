#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c = 1, d;
    cin >> a >> b;
    d = min(a, b);
    for (int i = 2; i <= d; i++){
        c *= i;
    }
    cout << c;
}