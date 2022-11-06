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

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i;
    string s;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> s;
        if (s.length() <= 10){
            cout << s << endl;
            continue;
        }
        printf("%c%d%c\n", s[0], s.length() - 2, s[s.length() - 1]);
    }
}