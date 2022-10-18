#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

int main(){
    string a;
    cin >> a;
    a[0] = toupper(a[0]);
    cout << a;
}