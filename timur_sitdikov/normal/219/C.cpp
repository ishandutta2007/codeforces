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

string s, s1;
int col[200];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, ans=0, n, k, cur;
    cin >> n >> k >> s;
    if (k>2)
    {
        for(i=1; i<n; i++)
        {
            col['A']=col['B']=col['C']=0;
            if (s[i]==s[i-1])
            {
                for(j='A'; ; j++)
                    if (s[i-1]!=j && (i==n-1 || s[i+1]!=j))
                        break;
                ans++;
                s[i]=j;
            }
        }
        cout << ans << endl << s;
        return 0;
    }
    s1=s;
    for(i=1; i<n; i++)
        if (s[i]==s[i-1])
        {
            ans++;
            s[i]='A'+'B'-s[i-1];
        }
    cur=ans;
    ans=1;
    s1[0]='A'+'B'-s1[0];
    for(i=1; i<n; i++)
        if (s1[i]==s1[i-1])
        {
            ans++;
            s1[i]='A'+'B'-s1[i-1];
        }
    if (ans<cur)
        cout << ans << endl  << s1;
    else
        cout << cur << endl  << s;
}