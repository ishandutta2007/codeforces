#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    char mn = '~';
    for(char c : s){
        puts(mn < c ? "Ann" : "Mike");
        mn = min(mn, c);
    }
}