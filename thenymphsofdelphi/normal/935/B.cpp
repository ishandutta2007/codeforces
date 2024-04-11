#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0, cnt = 0;
    if (s[0] == 'U'){
        y++;
    }
    else{
        x++;
    }
    if (s[1] == 'U'){
        y++;
    }
    else{
        x++;
    }
    for (int i = 2; i < n; i++){
        if (s[i] == s[i - 1] && x == y){
            cnt++;
        }
        if (s[i] == 'U'){
            y++;
        }
        else{
            x++;
        }
    }
    cout << cnt;
}