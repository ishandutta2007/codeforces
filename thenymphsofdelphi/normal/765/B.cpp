#include<bits/stdc++.h>
using namespace std;

string s;
int a[26];
int n, mx;

int main(){
    cin >> s;
    n = s.length();
    for (int i = 0; i < 26; i++){
        a[i] = 10000;
    }
    for (int i = 0; i < n; i++){
        a[s[i] - 'a'] = min(a[s[i] - 'a'], i);
        mx = max(mx, s[i] - 'a');
    }
    if (a[0] == 10000){
        cout << "NO";
        return 0;
    }
    for (int i = 1; i <= mx; i++){
        if (a[i] < a[i - 1] || a[i] == 10000){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}