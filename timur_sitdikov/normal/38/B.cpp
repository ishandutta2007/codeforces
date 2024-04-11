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

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s1, s2;
    int i,j,ans=0, x1, y1, x2, y2;
    cin >> s1 >> s2;
    x1=s1[0]-'a';
    y1=s1[1]-'1';
    x2=s2[0]-'a';
    y2=s2[1]-'1';
    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
        {
            if (i==x1 || j==y1)
                continue;
            if (i==x2 && j==y2)
                continue;
            if (abs(i-x2)==2 && abs(j-y2)==1 || 
                abs(i-x2)==1 && abs(j-y2)==2)
                continue;
            if (abs(i-x1)==2 && abs(j-y1)==1 || 
                abs(i-x1)==1 && abs(j-y1)==2)
                continue;
            ans++;
        }
    cout << ans;
}