#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < m; j++){
            a[i][j] = s[j];
        }
    }
    int ans = 0;
    vector <char> b(4);
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            b[0] = a[i][j];
            b[1] = a[i][j-1];
            b[2] = a[i-1][j];
            b[3] = a[i-1][j-1];
            sort(b.begin(), b.end());
            if (b[0] == 'a' && b[1] == 'c' && b[2] == 'e' && b[3] == 'f'){
                ans++;
            }
        }
    }
    cout << ans;
}