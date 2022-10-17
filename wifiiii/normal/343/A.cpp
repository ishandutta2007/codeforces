#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll a, ll b) {
    if(!a || !b) return 0;
    if(a > b) swap(a, b);
    return b / a + f(a, b % a);
}
int main() {
    ll a, b;
    cin >> a >> b;
    cout << f(a, b) << endl;
}