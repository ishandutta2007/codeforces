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

pair <long long, long long> pt1[3], pt2[3];
int m[3];

long long dimension(pair<long long, long long> pr1, pair<long long, long long> pr2, pair<long long, long long> pr3)
{return (pr2.first-pr1.first)*(pr3.second-pr1.second)-(pr3.first-pr1.first)*(pr2.second-pr1.second);}

long long sc_pr(pair<long long, long long> pr1, pair<long long, long long> pr2, pair<long long, long long> pr3)
{return (pr2.first-pr1.first)*(pr3.first-pr1.first)+(pr2.second-pr1.second)*(pr3.second-pr1.second);}

int on_seg(pair<long long, long long> pr1, pair<long long, long long> pr2, pair<long long, long long> pr3)
{
    if (dimension(pr1, pr2, pr3)) return 0;
    if ((pr1.first<=pr3.first && pr3.first<=pr2.first || pr2.first<=pr3.first && pr3.first<=pr1.first) &&
        (pr1.second<=pr3.second && pr3.second<=pr2.second || pr2.second<=pr3.second && pr3.second<=pr1.second)) return 1;
    return 0;
}

long long llabs(long long a)
{return a<0? -a: a;}

long long dis(pair<long long, long long> pr1, pair<long long, long long> pr2)
{return (pr1.first-pr2.first)*(pr1.first-pr2.first)+(pr1.second-pr2.second)*(pr1.second-pr2.second);}

int check()
{
    pair <long long, long long> p1[3], p2[3];
    long long d1, d2, d3 ,d4;
    int i;
    for(i=0; i<3; i++)
    {
        p1[i]=pt1[m[i]];
        p2[i]=pt2[m[i]];
    }
    if (p1[0]!=p2[1]) swap(p1[0], p2[0]);
    if (p1[0]!=p2[1]) swap(p1[1], p2[1]);
    if (p1[0]!=p2[1]) swap(p1[0], p2[0]);
    if (p1[0]!=p2[1]) return 0;
    swap(p1[1], p2[1]);
    if (on_seg(p1[0], p2[0], p2[1]) || on_seg(p1[1], p2[1], p2[0]) ) return 0;
    if (sc_pr(p1[0], p2[0], p2[1])<0) return 0;
    if (!on_seg(p1[0], p2[0], p1[2])) swap(p1[2], p2[2]);
    if (!on_seg(p1[0], p2[0], p1[2])) return 0;
    if (!on_seg(p1[1], p2[1], p2[2])) return 0;
    d1=dis(p1[0], p1[2]); d2=dis(p2[0], p1[2]);
    d3=dis(p1[1], p2[2]); d4=dis(p2[1], p2[2]);
    if (16*d1<d2 || 16*d2<d1 || 16*d3<d4 || 16*d4<d3) return 0;
    return 1;
}

int main()
{   
    int t, i, j, f;
    scanf("%d", &t);
    for(j=0; j<3; j++)
        m[j]=j;
    for(i=0; i<t; i++)
    {
        for(j=0; j<3; j++)
            scanf("%I64d %I64d %I64d %I64d", &pt1[j].first, &pt1[j].second, &pt2[j].first, &pt2[j].second);
        f=0;
        for(j=0; j<6; j++)
        {
            next_permutation(m, m+3);
            if (check()) 
                f=1;
        }
        if (f) printf("YES\n");
        else printf("NO\n");
    }
}