#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if (a < b - 1 || b == 0 || (b == 1 && a != 0)){
        cout << "No";
        return 0;
    }
    int ans = a - b + 1;
    if (ans % 2 == 1){
        cout << "No";
        return 0;
    }
    cout << "Yes";
}