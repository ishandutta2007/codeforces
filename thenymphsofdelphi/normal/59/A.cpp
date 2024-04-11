#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

int main(){
    string a;
    int n, i, cntu = 0, cntl = 0;
    cin >> a;
    n = a.length();
    for (i = 0; i < n; i++){
        if (isupper(a[i])){
            cntu++;
        }
        else{
            cntl++;
        }
    }
    if (cntu > cntl){
        for (i = 0; i < n; i++){
            putchar(toupper(a[i]));
        }
    }
    else{
        for (i = 0; i < n; i++){
            putchar(tolower(a[i]));
        }
    }
}