#include<bits/stdc++.h>
using namespace std;

bool isvowel(char a){
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
        return 1;
    }
    return 0;
}

int main(){
    string s;
    cin >> s;
    int n = s.length();
    if (n == 1){
        if (isvowel(s[0]) || s == "n"){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        return 0;
    }
    for (int i = 1; i < n; i++){
        if (s[i - 1] == 'n'){
            continue;
        }
        if (!isvowel(s[i - 1]) && !isvowel(s[i])){
            cout << "NO";
            return 0;
        }
    }
    if (!isvowel(s[n - 1]) && s[n - 1] != 'n'){
        cout << "NO";
        return 0;
    }
    cout << "YES";
}