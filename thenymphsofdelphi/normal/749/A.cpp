#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << n / 2 << endl;
    if (n % 2 == 0){
        while (n != 0){
            cout << 2 << " ";
            n -= 2;
        }
        return 0;
    }
    while (n != 3){
        cout << 2 << " ";
        n -= 2;
    }
    cout << 3 << " ";
}