#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mxN = 3e5;


struct edge {
    vector<int> adjList;
    int cost;
};  




int main() {
    int t = 1;

    for(int test_case =0; test_case < t; test_case++){
        // n ! choose (n / 2)!
        //
        vector<ll> fac(21);
        fac[0]=1;
        for(ll i = 1; i <= 20; i++) {
            fac[i] = fac[i - 1] * i;
        }

        int n;scanf("%d", &n);
        cout << fac[n] / (fac[n / 2] * fac[n / 2] * 2) * fac[n / 2 - 1] * fac[n / 2 - 1];
    }
}