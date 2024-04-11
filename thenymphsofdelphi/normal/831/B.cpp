#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    int val;
    for (int i = 0; i < c.length(); i++){
        if (isdigit(c[i])){
            cout << c[i];
            continue;
        }
        val = c[i] - 'A';
        if (islower(c[i])){
            val -= 32;
        }
        for (int i = 0; i < a.length(); i++){
            if (a[i] - 'a' == val){
                val = b[i];
                break;
            }
        }
        if (isupper(c[i])){
            val -= 32;
        }
        cout << (char)val;
    }
}