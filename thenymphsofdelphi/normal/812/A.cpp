#include<bits/stdc++.h>
using namespace std;

int main(){
    bool l[4], s[4], r[4], p[4];
    for (int i = 0; i < 4; i++){
        cin >> l[i] >> s[i] >> r[i] >> p[i];
    }
    for (int i = 0; i < 4; i++){
        if (p[i] && (l[i] || s[i] || r[i] || l[(i + 1) % 4] || s[(i + 2) % 4] || r[(i + 3) % 4])){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}