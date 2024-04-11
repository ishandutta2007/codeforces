#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (a + b + c == d + e + f){
        cout << "YES";
        return 0;
    }
    if (a + b + d == c + e + f){
        cout << "YES";
        return 0;
    }
    if (a + b + e == c + d + f){
        cout << "YES";
        return 0;
    }
    if (a + b + f == c + d + e){
        cout << "YES";
        return 0;
    }
    if (a + c + d == b + e + f){
        cout << "YES";
        return 0;
    }
    if (a + c + e == b + d + f){
        cout << "YES";
        return 0;
    }
    if (a + c + f == b + d + e){
        cout << "YES";
        return 0;
    }
    if (a + d + e == b + c + f){
        cout << "YES";
        return 0;
    }
    if (a + d + f == b + c + e){
        cout << "YES";
        return 0;
    }
    if (a + e + f == b + c + d){
        cout << "YES";
        return 0;
    }
    if (b + c + d == a + e + f){
        cout << "YES";
        return 0;
    }
    if (b + c + e == a + d + f){
        cout << "YES";
        return 0;
    }
    if (b + c + f == a + d + e){
        cout << "YES";
        return 0;
    }
    if (b + d + e == a + c + f){
        cout << "YES";
        return 0;
    }
    if (b + d + f == a + c + e){
        cout << "YES";
        return 0;
    }
    if (b + e + f == a + c + d){
        cout << "YES";
        return 0;
    }
    if (c + d + e == a + b + f){
        cout << "YES";
        return 0;
    }
    if (c + d + f == a + b + e){
        cout << "YES";
        return 0;
    }
    if (c + e + f == a + b + d){
        cout << "YES";
        return 0;
    }
    if (d + e + f == a + b + c){
        cout << "YES";
        return 0;
    }
    cout << "NO";
}