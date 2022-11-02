#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int c[110], c2[110];

int main () {
    int n, a;
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        mx = max (mx, a);
        for (int j = 1; j <= a; j++)
            c[j]++;
    }
    for (int i = 1; i <= mx; i++){
        for (int j = 1; j <= c[i]; j++)
            c2[j]++;
    }
    for (int i = n; i >= 1; i--){
        if (i != n)cout <<' ';
        cout << c2[i];
    }
}