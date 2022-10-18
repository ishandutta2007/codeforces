#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    if (s[0] == 'a' && s[1] == '1'){
        cout << 3;
        return 0;
    }
    if (s[0] == 'a' && s[1] == '8'){
        cout << 3;
        return 0;
    }
    if (s[0] == 'h' && s[1] == '1'){
        cout << 3;
        return 0;
    }
    if (s[0] == 'h' && s[1] == '8'){
        cout << 3;
        return 0;
    }
    if (s[0] == 'a'){
        cout << 5;
        return 0;
    }
    if (s[0] == 'h'){
        cout << 5;
        return 0;
    }
    if (s[1] == '1'){
        cout << 5;
        return 0;
    }
    if (s[1] == '8'){
        cout << 5;
        return 0;
    }
    cout << 8;
}