#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++){
        if (s[i] == '8'){
            cnt++;
        }
    }
    int ans = min(cnt, n / 11);
    cout << ans;
}