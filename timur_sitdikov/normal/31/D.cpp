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
#define point pair<int, int>
#define rect pair<point, point>
#define xx first
#define yy second

set<rect> st;
set<rect>::iterator it;
vector<rect> lines;

vector<int> ans;

char good[200];

int is_hor(rect & p)
{return p.first.yy==p.second.yy;}

int check(rect & p, rect& line)
{
    if (is_hor(line))
    {
        if (p.first.xx==line.first.xx && p.second.xx==line.second.xx &&
            p.first.yy<line.first.yy && p.second.yy>line.first.yy)
            return 1;
    }
    else
    {
        if (p.first.yy==line.first.yy && p.second.yy==line.second.yy &&
            p.first.xx<line.first.xx && p.second.xx>line.first.xx)
            return 1;
    }
    return 0;
}

rect fill(int x1, int y1, int x2, int y2)
{
    rect tmp;
    tmp.first.xx=x1;
    tmp.first.yy=y1;
    tmp.second.xx=x2;
    tmp.second.yy=y2;
    return tmp;
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int w, h, i, j, n, x1, y1, x2, y2;
    rect tmp, tmp1, tmp2;
    cin >> w >> h >> n;
    tmp=fill(0, 0, w, h);
    st.insert(tmp);
    for(i=0; i<n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        tmp=fill(x1, y1, x2, y2);
        lines.push_back(tmp);
    }
    for(i=0; i<n; i++)
    {
        it=st.begin();
        for(; it!=st.end(); it++)
        {
            for(j=0; j<n; j++)
            {
                if (good[j])
                    continue;
                if (check(*it, lines[j]))
                {
                    good[j]=1;
                    tmp1=fill((*it).first.xx, (*it).first.yy, lines[j].second.xx, lines[j].second.yy);
                    tmp2=fill(lines[j].first.xx, lines[j].first.yy, (*it).second.xx, (*it).second.yy);
                    st.insert(tmp1);
                    st.insert(tmp2);
                    st.erase(it);
                    goto ll;
                }
            }
        }
ll:     i=i;
    }
    for(it=st.begin(); it!=st.end(); it++)
        ans.push_back(((*it).second.xx-(*it).first.xx)*((*it).second.yy-(*it).first.yy));
    sort(ans.begin(), ans.end());
    for(i=0; i<=n; i++)
        printf("%d ", ans[i]);

}