#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

const int N = 2e5+7;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int k, b=1; cin >> k;
    while(b <= k) b += b;
    int z = b|k;
    cout << "2 3\n" << z << " " << k << " 0\n" << b << " " << z << " " << k << "\n";
}