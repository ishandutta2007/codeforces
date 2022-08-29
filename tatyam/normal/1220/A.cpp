#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s >> s;
    int one = count(s.begin(), s.end(), 'n'), zero = count(s.begin(), s.end(), 'z');
    while(one--) cout << "1 ";
    while(zero--) cout << "0 ";
}