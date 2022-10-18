#include<iostream>
using namespace std;

int main(){
    int a1, a2, a3, b1, b2, b3, a, b, s, m, n;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    cin >> s;
    a = a1 + a2 + a3;
    b = b1 + b2 + b3;
    if (a == 0) m = 0;
    else{
        a--;
        m = a / 5 + 1;
    }
    if (b == 0) n = 0;
    else{
        b--;
        n = b / 10 + 1;
    }
    if (m + n > s) cout << "NO";
    else cout << "YES";
}