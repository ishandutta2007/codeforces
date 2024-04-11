#include <bits/stdc++.h>

#define F first
#define S second
#define rsz resize
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using ld = double;
using pi = pair<int, int>;
using vpi = vector<pi>;

int f(int n) {
    return n & 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a; cin >> a; cout << f(a);
}