#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string a;
    int i;
    cin >> a;
    for (i = 2; i < a.length(); i++){
        if (a[i - 2] == 'W' && a[i - 1] == 'U' && a[i] == 'B'){
            a.replace(i - 2, 3, " ");
            i--;
        }
    }
    i = 0;
    //cout << a << "\n"; 
    while (a[i] == ' '){
        a.replace(i, 1, "");
    }
    //cout << a << "\n"; 
    i = a.length() - 1;
    while (a[i] == ' '){
        a.pop_back();
        i--;
    }
    //cout << a << "\n\n"; 
    for (i = 1; i < a.length(); i++){
        if (a[i] == ' ' && a[i - 1] == ' '){
            a.replace(i - 1, 2, " ");
            i--;
        }
        //cout << a << "\n"; 
    }
    cout << a;
}