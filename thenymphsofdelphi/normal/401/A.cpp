#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, m, s = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> x;
        s += x;
    }
    s = abs(s);
    x = s / m;
    if (s % m != 0){
        x++;
    }
    cout << x;
}