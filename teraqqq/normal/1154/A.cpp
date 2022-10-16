#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using pii = pair<int, int>;

const int N = 2e5+7;

int a[4];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 4; ++i) cin >> a[i];
    sort(a, a+4);
    for(int i = 0; i < 3; ++i) cout << a[3]-a[i] << ' ';
    cout << endl;
}