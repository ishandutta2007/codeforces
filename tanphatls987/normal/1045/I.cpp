#include <bits/stdc++.h>

using namespace std;

const int M = 26;
const int N = 1e5 + 10;
map<int, int> h;
int a[N];
int main() {
    int n;
    cin >> n; 


    long long ans = 0;
    while (n--) {
        string s;
        cin >> s;
        int pos = 0;
        for(auto ch : s) pos ^= 1 << (ch - 'a');

        ans += h[pos]; 
        for(int j = 0; j < M; j++) ans += h[pos ^ (1 << j)];
        h[pos]++;
    }
    cout << ans;
}