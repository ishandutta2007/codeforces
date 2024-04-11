#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

string s[10];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, a;
    cin >> n;
    n--;
    s[1] = "Sheldon";
    s[2] = "Leonard";
    s[3] = "Penny";
    s[4] = "Rajesh";
    s[5] = "Howard";        
    a = 1;
    while(n >= 5 * a){
        n -= 5 * a;
        a *= 2;
    }
    cout << s[n / a + 1];
}