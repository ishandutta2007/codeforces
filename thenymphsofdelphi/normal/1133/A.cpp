#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int h1, h2, m1, m2;
    h1 = (s1[1] - '0') + ((s1[0] - '0') * 10);
    h2 = (s1[4] - '0') + ((s1[3] - '0') * 10);
    m1 = (s2[1] - '0') + ((s2[0] - '0') * 10);  
    m2 = (s2[4] - '0') + ((s2[3] - '0') * 10);
    int a1 = (h1 * 60) + h2;
    int a2 = (m1 * 60) + m2;
    int x = (a1 + a2) / 2;
    if(x / 60 < 10) cout << "0";
    cout << x / 60 << ":";
    if(x % 60 < 10) cout << "0";
    cout << x % 60;
    return 0;
}