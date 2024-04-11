#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int s = 0;
    for(int i = 0; i < n; ++i) s += a[i];
    cout << s << '\n';
}