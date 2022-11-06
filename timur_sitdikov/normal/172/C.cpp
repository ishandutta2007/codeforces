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

pair<int, int> pr[100005], vc[100005];
int top;
long long ans[100005];

int main()
{   
    int i, j, k, n, m, tmp;
    long long time=0, last;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)
        scanf("%d %d", &pr[i].first, &pr[i].second);
    for(i=0; i<n; i+=j)
    {
        top=0;
        for(j=0; j<m && i+j<n; j++)
            vc[top++]=make_pair(pr[i+j].second, i+j);
        time=max(time, (long long)pr[i+j-1].first);
        sort(vc, vc+top);
        vc[top].first=1000000;
        last=0;
        for(j=0; j<top; j=k)
        {
            for(k=j+1; k<top && vc[k].first==vc[j].first; k++);
            tmp=k-j;
            time+=(vc[j].first-last);
            for(k=j; k<j+tmp; k++) ans[vc[k].second]=time;
            time+=(1+tmp/2);
            last=vc[j].first;
        }
        time+=last;
    }
    for(i=0; i<n; i++)
        printf("%I64d ", ans[i]);
}