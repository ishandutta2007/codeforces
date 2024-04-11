#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    cin >> s;
    if (s == "week"){
        if (n == 5 || n == 6){
            cout << 53;
        }
        else{
            cout << 52;
        }
        return 0;
    }
    if (n <= 29){
        cout << 12;
        return 0;
    }
    if (n <= 30){
        cout << 11;
        return 0;
    }
    cout << 7;
}