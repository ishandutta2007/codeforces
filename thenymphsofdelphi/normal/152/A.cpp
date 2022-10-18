#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    bool ck[n];
    memset(ck, 0, sizeof(ck));
    string s[n];
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    for (int i = 0; i < m; i++){
        int mx = -1;
        for (int j = 0; j < n; j++){
            mx = max(mx, s[j][i] - '0');
        }
        for (int j = 0; j < n; j++){
            if (s[j][i] - '0' == mx){
                ck[j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (ck[i]){
            cnt++;
        }
    }
    cout << cnt;
}