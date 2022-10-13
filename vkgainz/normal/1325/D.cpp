#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll u,v;
	cin >> u >> v;
    if (u%2!=v%2 || u>v) {
        printf("-1");
        return 0;
    }
    if (u==v) {
        if (!u)
			cout << 0 << endl;
        else
			cout << 1 << "\n" << u << endl;
        return 0;
    }
    ll x=(v-u)/2;
    if (u&x) cout << 3 << "\n" << u << " " << x << " " << x << endl;
    else cout << 2 << "\n" << (u^x) << " " << x << endl;
}