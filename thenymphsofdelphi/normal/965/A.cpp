#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, n, s, p;
    cin >> k >> n >> s >> p;
    n = (n + s - 1) / s;
    k *= n;
    cout << (k + p - 1) / p;
}