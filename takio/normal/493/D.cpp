#include<stdio.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;

int main () {
    int n;
    cin >> n;
    if (n % 2) {
        cout << "black";
    } else {
        cout << "white\n1 2";
    }
}