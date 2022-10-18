#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, i1, i2;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x == 1) i1 = i;
        else if (x == n) i2 = i;
    }
    cout << n - 1 - min(min(i1, n - i1 - 1), min(i2, n - i2 - 1));
}