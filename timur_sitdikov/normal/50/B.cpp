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

long long m[200];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    int i, j;
    long long ans;
    for(i=0; i<(int)s.length(); i++)
        m[s[i]]++;
    ans=0;
    for(i=0; i<200; i++)
        ans+=m[i]*m[i];
    cout << ans;
}