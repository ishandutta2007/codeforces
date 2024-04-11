#include<iostream>
using namespace std;

int main(){
    int a;
    cin >> a;
    int b = (a / 10) * 10, c = a % 10;
    if (c >= 5){
        b += 10;
    }
    cout << b;
}