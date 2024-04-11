#include <bits/stdc++.h>

using namespace std;

//#define TEST

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    long long ans = 0;
    vector<int> t(s.length() + 1, s.length());

    for(int i = s.length() - 1; i >= 0; i--){

        t[i] = t[i + 1];

        for(int k = 1; i + 2 * k < t[i]; k++){
            if(s[i] == s[i + k] && s[i + k] == s[i + 2 * k]){
                t[i] = i + 2 * k;
            }
        }

        ans += s.length() - t[i];

    }

    cout << ans << "\n";
    
    return 0;
}