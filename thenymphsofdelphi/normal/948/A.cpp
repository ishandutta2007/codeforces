#include<bits/stdc++.h>
using namespace std;

char a[700][700];

int main(){
    int n, m, i, j;
    cin >> n >> m;
    for (i = 0; i <= n + 1; i++){
        for (j = 0; j <= m + 1; j++){
            a[i][j] = '.';
        }
    }
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            if (a[i][j] == 'S'){
                if (a[i - 1][j] == 'W'){
                    cout << "No";
                    return 0;
                }
                if (a[i + 1][j] == 'W'){
                    cout << "No";
                    return 0;
                }
                if (a[i][j - 1] == 'W'){
                    cout << "No";
                    return 0;
                }
                if (a[i][j + 1] == 'W'){
                    cout << "No";
                    return 0;
                }
            }
        }
    }
    cout << "Yes\n";
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            if (a[i][j] == '.'){
                cout << 'D';
            }
            else{
                cout << a[i][j];
            }
        }
        cout << endl;
    }
}