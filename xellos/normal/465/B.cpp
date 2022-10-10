#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,a,ao =0,ans =0;
    cin >> N;
    for(int i =0; i < N; i++) {
        cin >> a;
        if(a == 1) ans++;
        if(a == 1 && ao == 0) ans++;
        ao =a;}
    cout << max(0,ans-1) << "\n";
    return 0;}