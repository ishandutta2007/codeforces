#include <bits/stdc++.h>
using namespace std;

int main() {
    int A[4];
    for(int i =0; i < 4; i++) cin >> A[i];
    if(A[1]-A[0] == A[2]-A[1] && A[3]-A[2] == A[2]-A[1]) {
        cout << A[3]+A[1]-A[0] << "\n";
        return 0;}
    if(A[1]*A[1] == A[0]*A[2] && A[2]*A[2] == A[3]*A[1] && A[1] != A[2]) {
        if((A[3]*A[3])%A[2] != 0) cout << "42\n";
        else cout << (A[3]*A[3])/A[2] << "\n";
        return 0;}
    cout << "42\n";    
    return 0;}