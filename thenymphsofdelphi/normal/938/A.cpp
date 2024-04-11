#include<bits/stdc++.h>
using namespace std;

bool isvowel(char a){
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'y'){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool a[n];
    memset(a, 0, sizeof(a));
    bool ck = 0;
    for (int i = 0; i < n; i++){
        if (isvowel(s[i])){
            if (ck){
                a[i] = 1;
            }
            else{
                ck = 1;
            }
        }
        else{
            ck = 0;
        }
    }
    for (int i = 0; i < n; i++){
        if (!a[i]){
            cout << s[i];
        }
    }
}