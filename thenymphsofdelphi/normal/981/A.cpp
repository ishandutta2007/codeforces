#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    char f = s[0];
    bool ck = false;
    for (int i = 1; i < n; i++){
        if (s[i] != f){
            ck = true;
            break;
        }
    }
    if (!ck){
        cout << 0;
        return 0;
    }
    string s2 = s;
    reverse(s2.begin(), s2.end());
    if (s2 == s){
        cout << n - 1;
        return 0;
    }
    cout << n;
}