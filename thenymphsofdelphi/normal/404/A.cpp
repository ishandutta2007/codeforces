#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    char x = s[0][0], y = s[0][1];
    if (x == y){
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j || i + j == n - 1){
                if (x != s[i][j]){
                    cout << "NO";
                    return 0;
                }
            }
            else{
                if (y != s[i][j]){
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES";
}