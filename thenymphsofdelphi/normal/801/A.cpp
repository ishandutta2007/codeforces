#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    cin >> s;
    int ans = 0, res;
    if (s.size() == 1){
        cout << 0;
        return 0;
    }
    for (int i = 0; i < (int)s.size() - 1; i++){
        ans += (s[i] == 'V' && s[i + 1] == 'K');
    }
    for (int p = 0; p < (int)s.size(); p++){
        s[p] = 'V' + 'K' - s[p];
        res = 0;
        for (int i = 0; i < (int)s.size() - 1; i++){
            res += (s[i] == 'V' && s[i + 1] == 'K');
        }
        ans = max(ans, res);
        s[p] = 'V' + 'K' - s[p];
    }
    cout << ans;
}