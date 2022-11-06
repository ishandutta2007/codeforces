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

int v[105];

int ret_val(int hh, int mm, char c)
{
    int ans=0;
    if (hh==12 && c=='a')
        return mm;
    if (hh==12 && c=='p')
        return 12*60+mm;
    if (c=='a') ans=hh;
    if (c=='p') ans=hh+12;
    ans*=60;
    ans+=mm;
    return ans;
}

int main()
{   
  
    int i, n, st=0, ans=1, hh, mm;
    char c[50];
    c[0]=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        while(c[0]!='[') c[0]=getchar();
        scanf("%d:%d %s", &hh, &mm, &c);
        v[i]=ret_val(hh, mm, c[0]);
    }
    for(i=1; i<n; i++)
    {
        if (v[i-1]>v[i]) 
        {ans++; st=i;}
        else if (v[i-1]==v[i] && i-st==10) 
        {ans++; st=i;}
        else if (v[i-1]<v[i]) st=i;
    }
    printf("%d", ans);
}