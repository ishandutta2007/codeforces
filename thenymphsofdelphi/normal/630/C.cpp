#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    n = pow(2, n + 1);
    n -= 2;
    cout << n;
}