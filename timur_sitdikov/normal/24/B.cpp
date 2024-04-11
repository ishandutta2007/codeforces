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

int val[12];
struct player
{int ct, m[55];};

map <string, player> mp;

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    string s;
    int n, i, j, m;
    map <string, player>::iterator it;
    string mx1, mx2;
    val[1]=25; val[2]=18;
    val[3]=15; val[4]=12;
    val[5]=10; val[6]=8;
    val[7]=6; val[8]=4;
    val[9]=2; val[10]=1;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &m);
        for(j=1; j<=m; j++)
        {
            cin >> s;
            if (j<=10)
            {
                mp[s].ct+=val[j];               
            }
            mp[s].m[j]++;
        }
    }
    it=mp.begin(); 
    mx1=it->first;
    for(it++; it!=mp.end(); it++)
    {
        if (it->second.ct>mp[mx1].ct) mx1=it->first;
        else if (it->second.ct==mp[mx1].ct) 
        {
            for(j=1; j<=50; j++)
            {
                if (it->second.m[j]>mp[mx1].m[j]) {mx1=it->first; break;}
                else if (it->second.m[j]<mp[mx1].m[j]) break;
            }
        }
    }
    it=mp.begin(); 
    mx2=it->first;
    for(it++; it!=mp.end(); it++)
    {
        if (it->second.m[1]>mp[mx2].m[1]) mx2=it->first;
        else if (it->second.m[1]==mp[mx2].m[1]) 
        {
            if (it->second.ct>mp[mx2].ct) mx2=it->first;
            else if (it->second.ct==mp[mx2].ct)
            {
                for(j=2; j<=50; j++)
                {
                    if (it->second.m[j]>mp[mx2].m[j]) {mx2=it->first; break;}
                    else if (it->second.m[j]<mp[mx2].m[j]) break;
                }
            }
        }
    }
    cout << mx1 << endl<< mx2;

}