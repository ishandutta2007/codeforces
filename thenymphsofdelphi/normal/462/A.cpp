#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    char a[n + 2][n + 2];
    memset(a, 'x', sizeof(a));
    for (int i = 1; i <= n; i++){
        cin >> s;
        for (int j = 1; j <= n; j++){
            a[i][j] = s[j - 1];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int cnt = 0;
            if (a[i - 1][j] == 'o') cnt++;
            if (a[i + 1][j] == 'o') cnt++;
            if (a[i][j - 1] == 'o') cnt++;
            if (a[i][j + 1] == 'o') cnt++;
            if (cnt % 2 != 0){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}