#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int k,n,w;
    cin >> k >> n >> w;
    int cost = w*(w+1)/2*k;
    if (cost<=n) cout << 0;
    else cout << cost-n;

    return 0;
}