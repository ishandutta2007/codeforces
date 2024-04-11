#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string d = s;
    reverse(d.begin(), d.end());
    cout << s << d;
}