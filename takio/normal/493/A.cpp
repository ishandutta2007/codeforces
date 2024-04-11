#include<stdio.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;

const int N = 100100;

int num[100][2];

int main () {
    string a[2];
    char c, k;
    int n, time, nn, t;
    cin >> a[0] >> a[1] >> n;
    while (n--) {
        cin >> time >> c >> nn >> k;
        if (c == 'a') t = 1; else t = 0;
        if (num[nn][t] >= 2) continue;
        if (k == 'r') {
            num[nn][t] += 2;
        } else num[nn][t]++;
        if (num[nn][t] >= 2) {
            cout << a[t] << ' ' << nn << ' ' << time << endl;
        }
    }
}