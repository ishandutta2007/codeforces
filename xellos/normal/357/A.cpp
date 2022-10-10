#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,x,y,S =0;
    cin >> N;
    vector<int> A(N);
    for(int i =0; i < N; i++) {
        cin >> A[i];
        S +=A[i];}
    cin >> x >> y;
    
    int s =0;
    if(x == 0) {cout << "1\n"; return 0;}
    for(int i =0; i < N-1; i++) {
        s +=A[i];
        if(s >= x && s <= y && S-s >= x && S-s <= y) {
            cout << i+2 << "\n"; 
            return 0;}}
    cout << "0\n";
    return 0;}