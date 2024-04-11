#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, a, b, c, d;
    cin >> n;
    while (1){
        n++;
        a = n % 10;
        b = (n % 100 - a) / 10;
        c = (n % 1000 - b * 10 - a) / 100;
        d = (n - c * 100 - b * 10 - a) / 1000;
        //cout << d << c << b << a << "\n"; 
        if (a != b && a != c && a != d && b != c && b != d && c != d){
            cout << n;
            return 0;
        }
    }
}