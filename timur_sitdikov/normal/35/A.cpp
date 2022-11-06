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

int m[4], i, a, b;

int main()
{   

        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    cin >> a;
    m[a]=1;
    for(i=0; i<3; i++)
    {
        cin >> a >> b;
        swap(m[a], m[b]);
    }
    for(i=1; i<=3; i++)
        if (m[i])
            cout << i;
}