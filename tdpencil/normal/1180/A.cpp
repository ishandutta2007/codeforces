#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll a;
    cin >> a;
    ll lst=1;
    for(int i = 1; i < a; i++)
        lst=4*i+lst;
    cout << lst;
}