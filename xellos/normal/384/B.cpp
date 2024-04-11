#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M,K;
    cin >> N >> M >> K;
    cout << M*(M-1)/2 << "\n";
    for(int i =0; i < M; i++)
        for(int j =i+1; j < M; j++) {
            if(K == 0) cout << i+1 << " " << j+1 << "\n";
            else cout << j+1 << " " << i+1 << "\n";}
    return 0;}