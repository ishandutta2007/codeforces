#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a = 0, b = 0;
    string s;
    cin >> s;
    n = s.length();
    if (n & 1){
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++){
        switch (s[i]){
            case 'L': a++; break;
            case 'R': a--; break;
            case 'U': b++; break;
            case 'D': b--; break;
        }
    }
    cout << (abs(a) + abs(b)) / 2;
}