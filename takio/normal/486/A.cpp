#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int main () {
    long long n;
    cin >> n;
    if (n & 1) cout << n / 2 - n << endl;
    else cout << n / 2 << endl;
}