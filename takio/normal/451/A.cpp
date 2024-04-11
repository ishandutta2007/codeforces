#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main () {
    int n, m;
    cin >>n >>m;
    int mn = min (n, m);
    if (mn % 2) cout << "Akshat";
    else cout << "Malvika";
}