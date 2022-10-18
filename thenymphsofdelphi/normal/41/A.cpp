#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){
    string a, b;
    int lena, lenb;
    cin >> a >> b;
    lena = a.length();
    lenb = b.length();
    if (lena != lenb){
        cout << "NO";
        return 0;
    }
    reverse(a.begin(), a.end());
    if (a == b){
        cout << "YES";
        return 0;
    }
    cout << "NO";
}