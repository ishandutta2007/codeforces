#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;

int main() {
    long long a, b;
    cin >> a >> b;
    long long p = b * (b - 1) / 2 % MOD, q = (a * (a + 1) / 2 % MOD * b + a) % MOD;
    cout << p * q % MOD << endl;
    return 0;
}