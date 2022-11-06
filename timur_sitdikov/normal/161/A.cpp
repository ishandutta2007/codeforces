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

pair <int, int> aa[100005], bb[100005];
vector<pair<int, int> > cc;
int n, m;

int main()
{   
    int i1, i2, ans=0, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for(i1=0; i1<n; i1++)
    {
        scanf("%d", &aa[i1].first);
        aa[i1].second=i1+1;
    }
    for(i1=0; i1<m; i1++)
    {
        scanf("%d", &bb[i1].first);
        bb[i1].second=i1+1;
    }
    sort(aa, aa+n);
    sort(bb, bb+m);
    for(i1=i2=0; i1<n && i2<m; )
    {
        if (aa[i1].first-x<=bb[i2].first && aa[i1].first+y>=bb[i2].first)
        {
            cc.push_back(make_pair(aa[i1].second, bb[i2].second));
            i1++; i2++; ans++;
        }
        else if (aa[i1].first-x>bb[i2].first) i2++;
        else i1++;
    }
    printf("%d\n", ans);
    for(i1=0; i1<ans; i1++)
        printf("%d %d\n", cc[i1].first, cc[i1].second);
}