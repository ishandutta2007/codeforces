#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    int n;
    cin >> n;
    cin >> a;
    int i, sublen = 1;
    for (i = 1; i <= n / 2; i++){
        if (a.substr(0, i) == a.substr(i, i)){
            sublen = i;
        }
    }
    cout << n - sublen + 1;
}