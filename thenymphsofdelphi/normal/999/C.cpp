#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n, k;
    cin >> n >> k;
    cin >> s;
    for (char c = 'a'; c <= 'z' && k > 0; c++){
        for (int i = 0; i < n && k > 0; i++){
            if (s[i] == c){
                s[i] = '0';
                k--;
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (s[i] == '0'){
            continue;
        }
        cout << s[i];
    }
}