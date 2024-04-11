//#include "grader.h"
#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define x first
#define y second
#define point pair <int, int>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
using namespace std;

long long a, b, c;

int main() {
    cin >> a >> b >> c;
    cout << min(a * 2 + b * 2, min(a + c + min(a + c, b), b + c + min(b + c, a)));
}