#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, x;
    cin >> a >> b >> x;
    int n = a + b;
    int s[n];
    for (int i = 0; i < x; i++){
        if (i == 0){
            if (a * 2 == x){
                s[i] = 1;
                b--;
            }
            else if (b * 2 == x){
                s[i] = 0;
                a--;
            }
            else if (x % 2 == 0){
                s[i] = 1;
                b--;
            }
            else{
                s[i] = 0;
                a--;
            }
        }
        else{
            s[i] = 1 - s[i - 1];
            if (s[i] == 0){
                a--;
            }
            else{
                b--;
            }
        }
    }
    for (int i = x; i < n; i++){
        if (a > 0){
            s[i] = 0;
            a--;
        }
        else{
            s[i] = 1;
        }
    }
    for (int i = 0; i < n; i++){
        cout << s[i];
    }
}