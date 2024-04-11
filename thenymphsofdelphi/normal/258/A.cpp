#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '0'){
            s.erase(s.begin() + i);
            cout << s;
            return 0;
        }
    }
    s.erase(s.begin());
    cout << s;
}