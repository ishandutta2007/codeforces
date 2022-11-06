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

map<int, int> mp;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, f, numo=0, nump=0, mini=200;
    map<int, int>::iterator it;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> f;
        if (n==1)
        {
            cout << f;
            return 0;
        }
        mp[f]++;
    }
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if (it->first<0)
            numo+=it->second;
        if (it->first>0)
            nump+=it->second;
    }
    if (!nump && numo<=1)
    {
        cout << "0";
        return 0;
    }
    if (numo&1)
        for(i=-1; ; i--)
            if (mp[i]>0)
            {
                mini=i;
                break;
            }
    for(i=-100; i<=100; i++)
    {
        if (!i)
            continue;
        if (i==mini)
            j=1;
        else j=0;
        for(; j<mp[i]; j++)
            cout << i << " ";
    }

}