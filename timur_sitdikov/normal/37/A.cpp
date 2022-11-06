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

bool cmp(int a, int b)
{return a<b;}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    map<int, int> mp;
    map<int, int>::iterator it;
    int n, i, a, mx=0 ,ans=0;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a;
        mp[a]++;
    }
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        ans++;
        if (it->second>mx)
            mx=it->second;
    }
    cout << mx <<" " <<  ans;


    
}