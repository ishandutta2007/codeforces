#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    if(N%2 == 0) cout << N*N/2 << "\n";
    else cout << N/2*N+N/2+1 << "\n";
    for(int i =0; i < N; i++) {
        for(int j =0; j < N; j++) cout << (((i+j)%2 == 0)?"C":".");
        cout << "\n";}
    return 0;}