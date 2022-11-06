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

struct team2{int val, g1, g2, dif, flag;};
struct team{string name; team2 tm2;} tm[200];

bool cmp(team a, team b)
{
    if (a.tm2.val<b.tm2.val) return true;
    if (a.tm2.val>b.tm2.val) return false;
    if (a.tm2.dif<b.tm2.dif) return true;
    if (a.tm2.dif>b.tm2.dif) return false;
    if (a.tm2.g1<b.tm2.g1) return true;
    else return false;
}

int main()
{   
    map<string, team2> mp;
    int i, j, n, a, b;
    string s1, s2, s;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        cin >> s;
        mp[s].flag=0;
    }
    for(i=0; i<n*(n-1)/2; i++)
    {
        cin >> s;
        s1.clear();
        for(j=0; s[j]!='-'; j++) s1.push_back(s[j]);
        j++; s2.clear();
        for(; j<(int)s.length(); j++)
            s2.push_back(s[j]);
        scanf("%d:%d", &a, &b);
        mp[s1].g1+=a; mp[s1].g2+=b; mp[s1].dif+=a-b;
        mp[s2].g1+=b; mp[s2].g2+=a; mp[s2].dif-=a-b;
        if (a>b) mp[s1].val+=3;
        else if (a<b) mp[s2].val+=3;
        else {mp[s1].val++; mp[s2].val++;}
    }
    map<string, team2>::iterator it;
    for(i=0, it=mp.begin(); it!=mp.end(); it++, i++)
    {
        tm[i].name=it->first;
        tm[i].tm2=it->second;
    }
    sort(tm, tm+n, cmp);
    for(i=0; i<n/2; i++) mp[tm[i].name].flag=1;
    for(it=mp.begin(); it!=mp.end(); it++)
        if (!(it->second.flag))
            cout << it->first << endl;
}