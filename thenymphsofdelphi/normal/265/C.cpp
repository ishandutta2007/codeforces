#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length(), l = 0, r = n - 1;
    int a[n];
    for (int i = 0; i < n; i++){
        if (s[i] == 'l'){
            a[r] = i + 1;
            r--;
        }
        else{
            a[l] = i + 1;
            l++;
        }
    }
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
}