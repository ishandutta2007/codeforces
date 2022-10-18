#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

int main(){
    string a;
    bool check = false;
    cin >> a;
    int len = a.length(), i, num = len / 2 + 1;
    int num1 = 0, num2 = 0, num3 = 0;
    for (i = 0; i < len; i++){
        if (a[i] == '1') num1++;
        else if (a[i] == '2') num2++;
        else if (a[i] == '3') num3++;
    }
    for (i = 0; i < num1; i++){
        if (check == false) check = true;
        else cout << "+";
        cout << "1";
    }
    for (i = 0; i < num2; i++){
        if (check == false) check = true;
        else cout << "+";
        cout << "2";
    }
    for (i = 0; i < num3; i++){
        if (check == false) check = true;
        else cout << "+";
        cout << "3";
    }
}