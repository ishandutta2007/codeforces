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

string s;
const int maxn=100015;
int last[maxn], num[maxn], g[200];
stack<pair<char, int> > stk;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, n, mn=-1, ss=0, f=-1;
    cin >> s;
    n=s.length();
    g['[']=']';
    g[']']='[';
    g['(']=')';
    g[')']='(';
    for(i=0; i<n; i++)
        last[i]=i+1;
    for(i=0; i<n; i++)
    {
        if (s[i]=='[' || s[i]=='(')
        {
            stk.push(mp(s[i], i));
        }
        else
        {
            if (stk.empty() || stk.top().first!=g[s[i]])
            {
                while(!stk.empty())
                    stk.pop();
            }
            else
            {
                last[i]=stk.top().second;
                stk.pop();
            }
        }
    }
    for(i=1; i<n; i++)
    {
        if (last[i])
            last[i]=min(last[i], last[last[i]-1]);
    }
    for(i=1; i<=n; i++)
        num[i]=num[i-1]+(s[i-1]=='[');
    for(i=0; i<n; i++)
    {
        if (num[i+1]-num[last[i]]>mn)
        {
            mn=num[i+1]-num[last[i]];
            ss=last[i];
            f=i;
        }
    }
    cout << mn << endl;
    for(i=ss; i<=f; i++)
        putchar(s[i]);
}