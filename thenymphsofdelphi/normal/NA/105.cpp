#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long n;
    cin >> n;
    n++;
    if (n == 1) cout << 0;
    else if (n % 2 == 0) cout << n / 2;
    else cout << n;
}