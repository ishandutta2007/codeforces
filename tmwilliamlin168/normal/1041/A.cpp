#include <bits/stdc++.h>
using namespace std;

int n, ai, mn=1e9, mx=0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> ai, mn=min(ai, mn), mx=max(ai, mx);
    cout << mx-mn+1-n;
}