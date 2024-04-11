#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    if (s == "0"){
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++){
        if (s[i] == '0'){
            cnt++;
        }
    }
    cout << '1';
    for (int i = 0; i < cnt; i++){
        cout << '0';
    }
}