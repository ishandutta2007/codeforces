#include <iostream>
#include <algorithm>
using namespace std;

int n, a[500005], l = 0, r = 0;

int main(){

    cin >> n;
    for(int i = 0; i<n; i++) cin>> a[i];
    sort(a, a+n);
    for( ; r<n; r++) if(a[r]>=2*a[l]) l++;
    cout << n-min(n/2, l);
       }