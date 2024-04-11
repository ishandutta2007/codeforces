#include <iostream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long a, b;

int ev(int a, int b) {
    return a ? ev(b % a, a) : b;
}

main() {
    cin >> a >> b;
    b /= ev(min(a, b), max(a, b));
    while (b % 2 == 0) {
        b /= 2;
    }
    if (b == 1) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}