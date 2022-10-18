#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    int n, m, i, j;
    cin >> a >> b;
    n = a.length();
    m = b.length();
    i = n - 1;
    j = m - 1;
    while (i >= 0 && j >= 0 && a[i] == b[j]){
        i--;
        j--;
    }
    i++;
    j++;
    cout << i + j;
}