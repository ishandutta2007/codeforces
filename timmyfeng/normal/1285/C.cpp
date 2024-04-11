#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll X;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> X;

    ll div = 1;
    for (ll i = 2; i * i <= X; i++)
        if (X % i == 0 && __gcd(i, X / i) == 1)
            div = i;
    cout << div << " " << X / div << "\n";
}