#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    n++;
    s.push_back(' ');
    int ans = 0, t = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == ' '){
            ans = max(ans, t);
            t = 0;
        }
        else{
            if (s[i] >= 'A' && s[i] <= 'Z'){
                t++;
            }
        }
    }
    cout << ans;
}