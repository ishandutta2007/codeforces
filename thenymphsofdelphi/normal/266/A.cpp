#include<iostream>
#include<string>
using namespace std;

int main(){
    int n, i, ct = 0;
    string a;
    cin >> n;
    cin >> a;
    for (i = 1; i < n; i++){
        if (a[i] == a[i - 1]) ct++;
    }
    cout << ct;
}