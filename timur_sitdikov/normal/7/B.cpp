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

map <pair<int, int>, int> mp;

int main()
{   
    int t, m, i, j, a, nn=1, f;
    char c[20];
    map <pair<int, int>, int>::iterator it, it1, it2;
    scanf("%d %d", &t, &m);
    mp[make_pair(0, 1)]=-1;
    mp[make_pair(m+1, m+1)]=0;
    for(i=0; i<t; i++)
    {
        scanf("%s", &c);
        if (c[0]=='a')
        {
            scanf("%d", &a);
            it=mp.begin();
            it1=it;
            f=0;
            for(it++; it!=mp.end(); it++)
            {
                if (it->first.first-it1->first.second>=a)
                {
                    mp[make_pair(it1->first.second, it1->first.second+a)]=nn;
                    printf("%d\n", nn);
                    nn++;
                    f=1; break;
                }
                it1=it;
            }
            if (!f) printf("NULL\n");           
        }
        else if (c[0]=='e')
        {
            scanf("%d", &a);
            if (a<=0) {printf("ILLEGAL_ERASE_ARGUMENT\n"); continue;}
            f=0;
            for(it=mp.begin(); it!=mp.end(); it++)
                if (it->second==a)
                {
                    f=1;
                    mp.erase(it);
                    break;
                }
            if (!f) printf("ILLEGAL_ERASE_ARGUMENT\n");
        }
        else
        {
            it=mp.begin();
            it1=it;
            f=0;
            for(it++; it->second!=0; )
            {
                if (it->first.first>it1->first.second)
                {
                    mp[make_pair(it1->first.second, it1->first.second+it->first.second-it->first.first)]=it->second;
                    it1++;
                    it2=it;
                    it++;
                    mp.erase(it2);
                }
                else
                {
                    it1=it;
                    it++;
                }
            }
        }
    }

}