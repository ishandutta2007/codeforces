#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (a == b && c == d && a == c){
        if (e == f){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (a == b && c == e && a == c){
        if (d == f){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (a == b && c == f && a == c){
        if (d == e){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (a == b && d == e && a == d){
        if (c == f){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (a == b && d == f && a == d){
        if (c == e){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (a == b && e == f && a == e){
        if (c == d){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (a == c && d == e && a == d){
        if (b == f){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (a == c && d == f && a == d){
        if (b == e){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (a == c && e == f && a == e){
        if (b == d){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (a == d && e == f && a == e){
        if (b == c){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (b == c && d == e && b == d){
        if (a == f){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (b == c && d == f  && b == d){
        if (a == e){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (b == c && e == f && b == e){
        if (a == d){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (b == d && e == f && b == e){
        if (a == c){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else if (c == d && e == f && c == e){
        if (a == b){
            cout << "Elephant";
        }
        else{
            cout << "Bear";
        }
    }
    else{
        cout << "Alien";
    }
}