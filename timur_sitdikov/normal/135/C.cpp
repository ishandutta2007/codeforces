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

char c[100005], c1[100005];
int ans[4];

void check()
{
    int i, n, o, s, z;
    n=strlen(c1);
    for(i=o=z=0; i<n; i++)
        if (c1[i]=='0') z++;
        else o++;
    if (z==o || z==o-1)
    {
        if (c1[n-1]=='1') ans[1]=1;
        else ans[2]=1;
    }
    else if (z<o-1) ans[3]=1;
    else ans[0]=1;
    return;
}

int main()
{   
    int i, n, o, z, o1, z1;
    scanf("%s", &c);
    n=strlen(c);
    for(i=o=z=0; i<n; i++)
        if (c[i]=='0') z++;
        else if (c[i]=='1') o++;
    for(i=0; i<n; i++)
        c1[i]=(c[i]=='0'? '0': '1');
    check();
    for(i=0; i<n; i++)
        c1[i]=(c[i]=='1'? '1': '0');
    check();
    o1=o; z1=z;
    for(i=0; i<n; i++)
        if (c[i]=='?')
        {
            if (z1<n/2) 
            {z1++; c1[i]='0';}
            else {c1[i]='1'; o1++;}
        }
        else
        {
            if (c[i]=='0') {c1[i]='0';}
            else {c1[i]='1';}
        }
    check();
    o1=o; z1=z;
    for(i=n-1; i>=0; i--)
        if (c[i]=='?')
        {
            if (z1<n/2) 
            {z1++; c1[i]='0';}
            else {c1[i]='1'; o1++;}
        }
        else
        {
            if (c[i]=='0') {c1[i]='0';}
            else {c1[i]='1';}
        }
    check();
    if (ans[0]) printf("00\n");
    if (ans[1]) printf("01\n");
    if (ans[2]) printf("10\n");
    if (ans[3]) printf("11\n");
}