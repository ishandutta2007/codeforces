#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a[3], b[3], c[3];
    cin >> n;
    for (int i = 0; i < 3; i++){
        cin >> a[i] >> b[i];
        c[i] = a[i];
        n -= c[i];
    }
    if (n == 0){
        for (int i = 0; i < 3; i++){
            cout << c[i] << endl;
        }
        return 0;
    }
    if (n <= b[0] - a[0]){
        c[0] += n;
        for (int i = 0; i < 3; i++){
            cout << c[i] << endl;
        }
        return 0;
    }
    c[0] = b[0];
    n -= b[0] - a[0];
    if (n <= b[1] - a[1]){
        c[1] += n;
        for (int i = 0; i < 3; i++){
            cout << c[i] << endl;
        }
        return 0;
    }
    c[1] = b[1];
    n -= b[1] - a[1];
    if (n <= b[2] - a[2]){
        c[2] += n;
        for (int i = 0; i < 3; i++){
            cout << c[i] << endl;
        }
        return 0;
    }
}