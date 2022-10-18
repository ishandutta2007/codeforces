#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    int h1 = 0, m1 = 0, h2 = 0, m2 = 0;
    cin >> a >> b;
    h1 = (a[0] - '0') * 10 + a[1] - '0';
    m1 = (a[3] - '0') * 10 + a[4] - '0';
    h2 = (b[0] - '0') * 10 + b[1] - '0';
    m2 = (b[3] - '0') * 10 + b[4] - '0';
    h1 -= h2;
    m1 -= m2;
    if (m1 < 0){
        m1 += 60;
        h1--;
    }
    if (h1 < 0){
        h1 += 24;
    }
    cout << h1 / 10 << h1 % 10 << ':' << m1 / 10 << m1 % 10;
}