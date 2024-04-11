#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string a, b;
    int i;
    cin >> a >> b;
    for (i = 0; i < a.length(); i++){
        if (a[i] == b[i]){
            cout << "0";
        }
        else{
            cout << "1";
        }
    }
}