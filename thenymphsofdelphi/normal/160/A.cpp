#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, a[100], i, tol = 0, v = 0;
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i];
        v += a[i];
    }
    sort(a, a + n);
    for (i = n - 1; i >= 0; i--){
        tol += a[i];
        if (tol > v / 2) break;
    }
    cout << n - i;
}