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

vector<int> ans;
stack<int> stk;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string cur, s, tmp;
    char c[5005];
    int i;
    s="";
    for(i=0; i<10; i++)
    {
        if (scanf("%s", &c)!=1)
            break;
        s+=c;
    }
    cur="";
    for(i=0; i<(int)s.size(); i++)
    {
        if (s[i]=='<')
            cur.clear();
        else if (s[i]=='>')
        {
            if (cur=="table")
            {
                stk.push(0);
            }
            else if (cur=="/table")
            {
                ans.pb(stk.top());
                stk.pop();
            }
            else if (cur=="td")
                stk.top()=stk.top()+1;
        }
        else cur.pb(s[i]);
    }
    sort(ans.begin(), ans.end());
    for(i=0; i<(int)ans.size(); i++)
        cout << ans[i] << " ";
}