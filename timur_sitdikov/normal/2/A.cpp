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
using namespace std;

map <string, int> res;
vector <pair <string, int> > cur;

int main()
{   
    int n, i, mx=0, v, sz;
    string st;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        cin >> st >> v;
        res[st]+=v;
        cur.push_back(make_pair(st, res[st]));
    }
    for(map<string, int>::iterator it=res.begin(); it!=res.end(); it++)
        if (it->second>mx) mx=it->second;
    sz=cur.size();
    for(i=0; i<sz; i++)
        if (cur[i].second>=mx && res[cur[i].first]==mx)
        {cout << cur[i].first; return 0;}
}