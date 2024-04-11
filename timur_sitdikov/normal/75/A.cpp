#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

int num(int s){
    string a;
    for(; s; s /= 10){
        if (s % 10){
            a.pb(s % 10);
        }
    }
    int ans = 0;
    for(int i = a.length() - 1; i >= 0; i--){
        ans = ans * 10 + a[i];  
    }
    return ans;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b, c, a1, b1, c1;
    cin >> a >> b;
    a1 = num(a);
    b1 = num(b);
    c = a + b;
    c1 = num(c);
    if (c1 == a1 + b1)
        printf("YES");
    else printf("NO");
}