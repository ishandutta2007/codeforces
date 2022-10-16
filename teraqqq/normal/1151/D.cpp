#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5+7;

ll sum;
int n, a, b, d[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b;
        sum += (ll)b*n-a;
        d[i] = a - b;
    }
    
    sort(d, d+n);
    for(int i = 0; i < n; ++i) 
        sum += (ll)d[i]*(n-i);
    cout << sum << endl;
}