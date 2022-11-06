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

vector<pair<long long, long long>> vc;
vector<int> pos;

long long gcd(long long a, long long b)
{
    vc.push_back(make_pair(a, b));
    return b? gcd(b, a%b): a;
}

int main()
{   
    long long a, b, g, sz, q;
    int i, t, j;
    scanf("%d", &t);
    for(j=0; j<t; j++)
    {
        scanf("%I64d %I64d", &a, &b);
        if (!a || !b) {printf("Second\n"); continue;}
        vc.clear();
        pos.clear();
        if (a<b) swap(a, b);
        g=gcd(a, b);
        sz=vc.size();
        for(i=0; i<sz; i++) pos.push_back(1);
        for(i=0; i<sz; i++)
        {
           // vc[i].first/=g;
           // vc[i].second/=g;
            swap(vc[i].first, vc[i].second);
        }
        reverse(vc.begin(), vc.end());
        for(i=1; i<sz; i++)
        {
            if (pos[i-1]) pos[i]=0;
            else
            {
                q=vc[i].second/vc[i].first;
                if (vc[i].first&1)
                {
                    if (q&1) pos[i]=1;
                    else pos[i]=0;
                }
                else
                {
                    q%=(vc[i].first+1);
                    if (q&1) pos[i]=1;
                    else pos[i]=0;
                }
            }
        }
        if (pos[sz-1]) printf("Second\n");
        else printf("First\n");
    }
}