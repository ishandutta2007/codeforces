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
#define point complex<double>

string s;
char used[200];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, n, k, j;
    cin >> k >> s;
    n=s.length();
    for(i=0; i<n; i++)
    {
        if (s[i]!='?' && s[n-1-i]!='?' && s[i]!=s[n-1-i])
        {
            printf("IMPOSSIBLE");
            return 0;
        }
        if (s[i]!='?')
            s[n-1-i]=s[i];
        if (s[n-1-i]!='?')
            s[i]=s[n-1-i];
        used[s[i]]=1;
    }
    for(i=(n-1)/2; i>=0; i--)
        if (s[i]=='?')
        {
            for(j='a'+k-1; j>='a'; j--)
                if (!used[j])
                {
                    used[j]=1;
                    s[i]=s[n-1-i]=j;
                    break;
                }
            if (j=='a'-1)
                s[i]=s[n-1-i]='a';
        }
    for(j='a'; j<='a'+k-1; j++)
        if (!(used[j]))
        {
            printf("IMPOSSIBLE");
            return 0;
        }
    cout << s;
}