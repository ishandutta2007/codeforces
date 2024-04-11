#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "";
    int n, t, dig;
    cin >> n;
    for (int i = 400; i >= 1; i--){
        t = i;
        while (t != 0){
            dig = t % 10;
            s.push_back(dig + '0');
            t /= 10;
        }
    }
    reverse(s.begin(), s.end());
    n--;
    cout << s[n];
}