#include <iostream>
#include <string>

using namespace std;

const int N = 2e5+5;

int n;
long long b[N], a[N], amin, amax=1e18;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n; n /= 2;
    for(int i = 0; i < n; ++i) {
        cin >> b[i];

        if(b[i] - amin > amax)
            a[i] = b[i] - amax;
        else a[i] = amin;

        amin = max(amin, a[i]);
        amax = min(amax, b[i] - a[i]);
    }

    for(int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    for(int i = n-1; i >= 0; --i)
        cout << b[i] - a[i] << ' ';
}