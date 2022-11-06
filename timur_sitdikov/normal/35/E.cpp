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
const int inf=1000000000;

struct seg
{
    int h, x, type;
};

seg make_seg(int h, int x, int type)
{
    seg tmp;
    tmp.h=h;
    tmp.x=x;
    tmp.type=type;
    return tmp;
}

map<int, int> vv;
vector<seg> segs;
vector<pair<int, int> > ans;

bool cmp(seg &s1, seg &s2)
{
    if (s1.x!=s2.x)
        return s1.x<s2.x;
    return s1.type<s2.type;
}

int main()
{   
    //#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    //#endif
    int n, i, j, l, r, h, last, cur;
    map<int, int>::iterator it;
    cin >> n;
    for(i=0; i<n; i++)
    {
        scanf("%d %d %d", &h, &l, &r);
        segs.pb(make_seg(h, l, 1));
        segs.pb(make_seg(h, r, 0));
    }
    sort(segs.begin(), segs.end(), cmp);
    last=0;
    vv[0]=1;
    for(i=0; i<segs.size(); )
    {
        for(j=i; j<segs.size() && segs[j].x==segs[i].x; j++)
        {
            if (!segs[j].type)
            {
                vv[segs[j].h]--;
                if (vv[segs[j].h]==0)
                    vv.erase(segs[j].h);
            }
            else
            {
                vv[segs[j].h]++;
            }
        }
        it=vv.end();
        it--;
        cur=it->first;
        if (cur!=last)
        {
            ans.pb(mp(segs[i].x, last));
            ans.pb(mp(segs[i].x, cur));
        }
        last=cur;
        i=j;
    }
    printf("%d\n", (int)ans.size());
    for(i=0; i<(int)ans.size(); i++)
        printf("%d %d\n", ans[i].first, ans[i].second);
}