#include <bits/stdc++.h>

using namespace std;

//#define TEST

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    bool left = false;
    bool right = false;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            cout << (left ? 1 : 0);
            left = !left;
        }
        else{
            cout << (right ? 1 : 0);
            right = !right;
        }
    }
    cout << "\n";
    
    return 0;
}