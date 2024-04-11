#include <bits/stdc++.h>

using namespace std;

const int N = 97;

int n, k;
char s[N];

int dist(char c1, char c2) {
    int dist = abs(c1 - c2);
    return min(dist, 26-dist);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    for(int i = 3; i < n; ++i) {
        int d = dist(s[i-3], 'A')
              + dist(s[i-2], 'C')
              + dist(s[i-1], 'T')
              + dist(s[i-0], 'G');
        if(i == 3) k = d;
        k = min(k, d);
    }
    
    cout << k;
}