#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin >> n >> s;
        bool ck = 1;
        for (int i = 0; i < n / 2; i++){
            int j = n - 1 - i;
            if (s[i] == s[j]){
                continue;
            }
            if (s[i] == 'a' && s[j] != 'c'){
                ck = 0;
                break;
            }
            if (s[j] == 'a' && s[i] != 'c'){
                ck = 0;
                break;
            }
            if (s[i] == 'z' && s[j] != 'x'){
                ck = 0;
                break;
            }
            if (s[j] == 'z' && s[i] != 'x'){
                ck = 0;
                break;
            }
            int dif;
            if (s[i] > s[j]){
                dif = s[i] - s[j];
                if (dif != 2){
                    ck = 0;
                    break;
                }
            }
            else{
                dif = s[j] - s[i];
                if (dif != 2){
                    ck = 0;
                    break;
                }
            }
        }
        if (ck){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}