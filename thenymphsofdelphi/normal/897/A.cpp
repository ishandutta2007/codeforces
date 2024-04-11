#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, l, r;
    string s;
    char a, b;
    cin >> n >> m >> s;
    while (m--){
        cin >> l >> r >> a >> b;
        l--;
        r--;
        for (int i = l; i <= r; i++){
            if (s[i] == a) s[i] = b;
        }
    }
    cout << s;
}