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

map<string, set<string> > mp;
map<string, set<string> >::iterator it;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s1, s2;
    int n, i, ans=0;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> s1 >> s2;
        mp[s1].insert(s2);
    }
    for(it=mp.begin(); it!=mp.end(); it++)
        ans+=it->second.size();
    cout << ans;
    
}