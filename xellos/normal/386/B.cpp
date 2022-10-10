#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,T;
    cin >> N;
    vector<int> t(N);
    for(int i =0; i < N; i++) cin >> t[i];
    cin >> T;
    int ans =0;
    for(int i =0; i < N; i++) {
        int akt =0;
        for(int j =0; j < N; j++) 
            if(t[j] >= t[i] && t[j] <= T+t[i]) akt++;
        ans =max(ans,akt);}
    cout << ans << "\n";
    return 0;}