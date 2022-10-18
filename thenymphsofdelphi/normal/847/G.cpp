#include<bits/stdc++.h>
using namespace std;

int cnt[7];

int main(){
    int n, mx = -1;
    string s;
    cin >> n;
    while (n--){
        cin >> s;
        for (int i = 0; i < 7; i++){
            if (s[i] == '1'){
                cnt[i]++;
            }
        }
    }
    for (int i = 0; i < 7; i++){
        mx = max(mx, cnt[i]);
    }
    cout << mx;
}