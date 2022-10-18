#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, a, b, c, d;
    cin >> s;
    s = "      " + s;
    int cnt = 0;
    for (int i = 6; i < s.length(); i++){
        a = s.substr(i - 2, 3);
        b = s.substr(i - 3, 4);
        c = s.substr(i - 4, 5);
        d = s.substr(i - 5, 6);
        if (a == "Ann" || b == "Olya" || c == "Danil" || c == "Slava" || d == "Nikita"){
            cnt++;
        }
    }
    if (cnt == 1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}