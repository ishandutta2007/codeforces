#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n/2 << "\n";
    for(int i=0; i<n/2; ++i)
        cout << (i==0?n%2:0)+2 << " ";
}