#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < m; j++){
            if (s[j] == '-'){
                cout << '-';
                continue;
            }
            if ((i + j) % 2 == 0) cout << 'B';
            else cout << 'W';
        }
        cout << '\n';
    }
}