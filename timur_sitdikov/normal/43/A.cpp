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

map<string, int> m;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, mx;
    string s;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        m[s]++;
    }
    mx=0;
    for(map<string, int>::iterator it=m.begin(); it!=m.end(); it++)
    {
        if (mx<it->second)
        {
            mx=it->second;
            s=it->first;
        }
    }
    cout << s;
}