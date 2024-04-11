#include<bits/stdc++.h>
using namespace std;

void INI_OK(int n){
    cout << "YES\n" << n;
    exit(0);
}

int main(){
    string s;
    int n;
    cin >> s;
    n = s.length();
    int a[n];
    for (int i = 0; i < n; i++){
        a[i] = s[i] - '0';
    }
    for (int i = 0; i < n; i++){
        if (a[i] == 0 || a[i] == 8){
            INI_OK(a[i]);
        }
    }
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if ((a[i] * 10 + a[j]) % 8 == 0){
                INI_OK(a[i] * 10 + a[j]);
            }
        }
    }
    for (int i = 0; i < n - 2; i++){
        for (int j = i + 1; j < n - 1; j++){
            for (int k = j + 1; k < n; k++){
                if ((a[i] * 100 + a[j] * 10 + a[k]) % 8 == 0){
                    INI_OK(a[i] * 100 + a[j] * 10 + a[k]);
                }
            }
        }
    }
    cout << "NO";
}