#include <iostream>
using namespace std;

int main(){
    int n, k, i;
    cin >> n >> k;
    int a[n];
    for (i = 0; i < n; i++){
        cin >> a[i];
    }
    int val = a[k - 1];
    i = 0;
    while (a[i] >= val && a[i] > 0){
        i++;
        if (i == n) break;
    }
    cout << i;
}