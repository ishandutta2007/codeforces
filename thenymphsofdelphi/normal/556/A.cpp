#include<bits/stdc++.h>
using namespace std;

int main(){
    int c0 = 0, c1 = 0, n;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++){
        if (s[i] - '0' == 0) c0++;
        else c1++;
    }
    cout << n - 2 * min(c0, c1);
}