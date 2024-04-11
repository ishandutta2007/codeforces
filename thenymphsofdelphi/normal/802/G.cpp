#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, x = "heidi.";
    int n, a[6], t = 0;
    for (int i = 0; i < 6; i++){
        a[i] = 1e6;
    }
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++){
        if (s[i] == x[t]){
            a[t] = i;
            t++;
        }
    }
    if (a[4] != 1e6){
        cout << "YES";
        return 0;
    }
    cout << "NO";
}