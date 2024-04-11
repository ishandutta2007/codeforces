#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n, k, cnt = 0, num = 0;
    cin >> s >> k;
    n = s.length();
    for (int i = 0; i < n; i++){
        if (s[i] == '0'){
            cnt++;
        }
        num *= 10;
        num += s[i] - '0';
    }
    if (cnt < k){
        cout << n - 1;
        return 0;
    }
    if (num % (int)(pow(10, k)) == 0){
        cout << 0;
        return 0;
    }
    cnt = 0;
    for (int i = n - 1; i >= 0; i--){
        if (s[i] == '0'){
            cnt++;
        }
        if (cnt == k){
            cout << n - i - k;
            return 0;
        }
    }
}