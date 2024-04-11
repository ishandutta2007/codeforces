#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0){
        cout << "NO";
        return 0;
    }
    if (abs(a - b) > 1){
        cout << "NO";
        return 0;
    }
    cout << "YES";
}