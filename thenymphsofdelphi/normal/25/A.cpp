#include<iostream>
using namespace std;

int main(){
    int n, i, num0 = 0, num1 = 0, val0, val1;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] % 2 == 0){
            num0++;
            val0 = a[i];
        }
        else{
            num1++;
            val1 = a[i];
        }
    }
    if (num0 < num1){
        for (i = 0; i < n; i++){
            if (a[i] == val0){
                cout << i + 1;
                return 0;
            }
        }
    }
    else{
        for (i = 0; i < n; i++){
            if (a[i] == val1){
                cout << i + 1;
                return 0;
            }
        }
    }
}