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

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    int n, k, a, b, i, j, lim;
    cin >> k >> a >> b >> s;
    n=s.length();
    if (a*k>n || b*k<n)
    {
        cout << "No solution";
        return 0;
    }
    lim=k-n%k;
    for(i=j=0; i<lim; i++)
    {
        cout << s.substr(j, n/k) << endl;
        j+=n/k;
    }
    for(; i<k; i++)
    {
        cout << s.substr(j, n/k+1) << endl;
        j+=n/k+1;
    }
}