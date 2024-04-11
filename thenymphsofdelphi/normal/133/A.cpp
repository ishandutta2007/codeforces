#include<iostream>
#include<string>
using namespace std;

int main(){
    string a;
    int len, i;
    cin >> a;
    len = a.length();
    for (i = 0; i < len; i++){
        if (a[i] == 'H' || a[i] == 'Q' || a[i] == '9'){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}