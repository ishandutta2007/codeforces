#include<iostream>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;

int main(){
    long x, mx = LONG_MIN, y, n, i, a[1000];
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] >= 0){
            y = sqrt(a[i]);
            if (y * y != a[i]){
                mx = max(mx, a[i]);
            }
        }
        else{
            mx = max(mx, a[i]);
        }
    }
    cout << mx;
}