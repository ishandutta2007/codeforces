#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, ans = 0;
    cin >> n >> k;
    string s;
    for (int i = 0; i < n; i++){
        cin >> s;
        int cnt = 0;
        for (int j = 0; j < s.length(); j++){
            if (s[j] == '4' || s[j] == '7'){
                cnt++;
            }
        }
        if (cnt <= k){
            ans++;
        }
    }
    cout << ans;
}