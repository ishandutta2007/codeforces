#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    for (int i = 0; i <= 100; i++){
        if (a > b){
            cout << i;
            return 0;
        }
        a *= 3;
        b *= 2;
    }
}