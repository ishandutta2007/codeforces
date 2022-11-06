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

int mx, n, i, j, reg, cur, sum=0, t=0, mini;
char used[1005];
pair<int, pair<int, int> > m[1005];
vector<pair<int, int>> time;

bool cmp(pair<int, pair<int, int> >  a, pair<int, pair<int, int> >  b)
{
    if (a.first!=b.first)
        return a.first>b.first;
    return a.second.first>b.second.first;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> mx >> reg;
    cur=mx;
    for(i=0; i<n; i++)
    {
        cin >> m[i].first >> m[i].second.first;
        m[i].second.second=i;
    }
    sort(m, m+n, cmp);
    m[n]=make_pair(-1, make_pair(0, 0));
    for(t=0; ; t++)
    {
        mini=-1;
        for(i=0; i<n; i++)
            if (m[i].first*mx>=cur*100 && !used[i] && (mini==-1 || m[i].second.first>m[mini].second.first))
            {
                mini=i; 
            }
        if (mini!=-1)
        {
            sum+=m[mini].second.first;
            time.pb(make_pair(t, m[mini].second.second));
            used[mini]=1;
        }
        else
        {
            if (sum<=reg)
            {
                printf("NO");
                return 0;
            }
        }
        cur-=sum;
        cur+=reg;
        if (cur>mx)
            cur=mx;
        if (cur<=0)
            break;
    }
    printf("YES\n");
    printf("%d %d\n", t+1, time.size());
    sort(time.begin(), time.end());
    for(i=0; i<(int)time.size(); i++)
        printf("%d %d\n", time[i].first, time[i].second+1);
}