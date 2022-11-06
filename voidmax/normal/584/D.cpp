#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a; i > b; --i)
#define pb push_back
#define inf 1e9
#define x first
#define y second
#define ins insert

using namespace std;

bool prime(int n) {
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    if (prime(n)) {
        cout << 1 << endl << n << endl;
        return 0;
    }
    if (prime(n - 2)) {
        cout << 2 << endl << 2 << ' ' << n - 2 << endl;
        return 0;
    }
    for(int i = 3; i < n - 3; i+=2)
        if (prime(i) && prime(n - i - 3)) {
            cout << 3 << endl << 3 << ' ' << i << ' ' << n - i - 3 << endl;
            break;
        }
}