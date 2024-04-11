#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string s2 = s;
    sort(s2.begin(), s2.end());
    if (s2 != s){
        cout << "NO";
        return 0;
    }
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.length(); i++){
        switch (s[i]){
            case 'a': a++; break;
            case 'b': b++; break;
            case 'c': c++; break;
        }
    }
    if (a == 0 || b == 0 || (a != c && b != c)){
        cout << "NO";
        return 0;
    }
    cout << "YES";
}