#include<iostream>
using namespace std;

int main(){
    long tol, k, n;
    cin >> k >> tol >> n;
    long add = k * (n * (n + 1) / 2);
    add -= tol;
    if (add < 0) cout << "0";
    else cout << add;
    cout << endl;
}