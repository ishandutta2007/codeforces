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

deque <int> ans;

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    int n, i;
    cin >> s;
    n = s.length();
    ans.push_back(n);
    for(i = n - 2; i >= 0; i--){
        if (s[i] == 'l')
            ans.push_back(i + 1);
        else
            ans.push_front(i + 1);
    }
    for(i = 0; i < n; i++){
        printf("%d\n", ans.front());
        ans.pop_front();
    }
}