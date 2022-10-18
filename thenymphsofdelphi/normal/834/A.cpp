#include<bits/stdc++.h>
using namespace std;

int main(){
    char c, d;
    int n;
    cin >> c >> d >> n;
    n %= 4;
    if (n == 2 || n == 0){
        cout << "undefined";
        return 0;
    }
    int a, b;
    switch (c){
        case 'v': a = 0; break;
        case '<': a = 1; break;
        case '^': a = 2; break;
        case '>': a = 3; break;
    }
    switch (d){
        case 'v': b = 0; break;
        case '<': b = 1; break;
        case '^': b = 2; break;
        case '>': b = 3; break;
    }
    if (abs(a - b) % 2 == 0){
        cout << "undefined";
        return 0;
    }
    if (n == 1){
        if (a - b == -1 || a - b == 3){
            cout << "cw";
            return 0;
        }
        cout << "ccw";
        return 0;
    }
    else{
        if (a - b == 1 || a - b == -3){
            cout << "cw";
            return 0;
        }
        cout << "ccw";
        return 0;
    }
}