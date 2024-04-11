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

string s;

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, j, n, t;
    cin >> n >> t >> s;
    for(i = 0; i < t; i++){
        for(j = 1; j < n; ){
            if (s[j - 1] == 'B' && s[j] == 'G'){
                swap(s[j - 1], s[j]);
                j += 2;
            }
            else{
                j++;
            }
        }
    }
    cout << s;
}