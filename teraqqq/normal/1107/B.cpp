#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

int q, x;
ll k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(cin >> q; q--;) {
    	cin >> k >> x;
    	cout << (k-1)*9+x << endl;
    }
}