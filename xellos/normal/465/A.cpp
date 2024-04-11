#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int N;
    cin >> N >> s;
    int ans =0;
    for(int i =0; i < N; i++) {
        if(s[i] == '0') {ans++; break;}
        ans++;}
    cout << ans << "\n";
    return 0;}