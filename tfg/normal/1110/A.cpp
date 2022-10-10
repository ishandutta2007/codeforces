#include <iostream>
using namespace std;

int main() {
    int b ,k,k2,n;
    k2 = 1;
    cin >> b;
    cin >> k;
    int a[k];
    n = 0;
    for (int l = 0; l < k ; l++) {
        cin >> a[l];
    }
    for (int i = k-1; i>=0; i--) {
        k2 = (i==k-1) ? : k2*b%2;
        a[i] = a[i]*k2%2;
        n = (n+a[i])%2;
    }

    cout << ((n%2)!=1 ? "even" : "odd");

    return 0;
}