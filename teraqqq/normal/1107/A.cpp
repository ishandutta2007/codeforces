#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int N = 305;

int q, n;
char s[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(cin >> q; q--;) {
    	cin >> n >> s;
    	if(n == 2 && s[0] >= s[1]) cout << "NO" << endl;
    	else cout << "YES" << endl << 2 << endl << s[0] << ' ' << &s[1] << endl;
    }
}