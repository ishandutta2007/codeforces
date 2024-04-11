#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, x, b[100];
    int i;
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> x;
        b[x - 1] = i + 1;
    }
    for (i = 0; i < n; i++){
        cout << b[i] << " ";
    }
}