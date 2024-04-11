#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int n, x = 0, i;
    cin >> n;
    string a;
    for (i = 0; i < n; i++){
        cin >> a;
        if (a[1] == '+') x++;
        else x--;
    }
    cout << x;
}