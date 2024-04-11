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
#define xx first
#define yy second

int mod[4], per[4];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, j, k, a, b, v, ans = 0, cur;
    cin>> mod[0] >> mod[1] >> mod[2] >> mod[3] >> a >> b ;
    for(i = a; i <= b; i++){
        cur = 0;
        for(j = 0; j < 4; j++)
            per[j] = j;
        for(k = 0; k < 24; k++){
            v = i;
            for(j = 0; j < 4; j++)
                v = v % mod[per[j]];
            if (v == i)
                cur++;
            next_permutation(per, per + 4);
        }
        if (cur >= 7)
            ans++;
    }
    cout << ans;
}