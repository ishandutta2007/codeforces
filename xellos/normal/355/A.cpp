#include <bits/stdc++.h>
using namespace std;

int main() {
    int K,D;
    cin >> K >> D;
    if(D == 0) {
        if(K == 1) cout << "0\n";
        else cout << "No solution\n";
        return 0;}
    cout << D;
    for(int i =1; i < K; i++) cout << "0";
    cout << "\n";
    return 0;}