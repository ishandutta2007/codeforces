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

string st[3], st_tmp;
long long hsh[3][100005], p[100505], mod=997, good[3];
int pf[200005];

int kmp()
{
    int i, j, ans=0;
    for(i=1; i<st_tmp.length(); i++)
    {
        for(j=pf[i-1]; j && st_tmp[j]!=st_tmp[i]; j=pf[j-1]);
        if (st_tmp[j]==st_tmp[i]) j++;
        pf[i]=j;
        ans=max(ans, pf[i]);
    }
    return ans;
}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, m[3], i, j, k, sz, ans, sum=0, cur[2], c1, c2, lim=0;
    long long tmp1, tmp2;
    cin >> st[0] >> st[1] >> st[2];
    p[0]=1;
    for(i=1; i<100003; i++)
        p[i]=p[i-1]*mod;
    for(k=0; k<3; k++)
        for(i=0; i<st[k].size(); i++)
            hsh[k][i+1]=hsh[k][i]+st[k][i]*p[i];
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
        {
            if (i==j) continue;
            st_tmp=st[i]+"#"+st[j];
            c1=kmp();
            if (c1==st[i].size()) 
            {
                if (st[j].size()!=c1 || !good[j])
                good[i]=1;
            }
        }
    for(k=0; k<3; k++) if (!good[k]) lim++;
    for(i=j=0; i<3; i++) if (!good[i]) m[j++]=i;
    for(i=0; i<3; i++) if (!good[i]) sum+=st[i].size();
    ans=sum;
    if (lim==1) {printf("%d", ans); return 0;}
    cur[0]=cur[1]=0;
    for(k=0; k<6; k++)
    {       
        for(j=0; j<lim-1; j++)
        {
            sz=min(st[m[j]].size(), st[m[j+1]].size());
            for(i=st[m[j]].size()-sz; i<st[m[j]].size(); i++)
            {
                tmp1=hsh[m[j]][st[m[j]].size()]-hsh[m[j]][i];
                tmp2=hsh[m[j+1]][st[m[j]].size()-i]*p[i];
                if (tmp1==tmp2) break;
            }
            cur[j]=st[m[j]].size()-i;
        }
        c1=(int)st[m[0]].size()+(int)st[m[1]].size()-cur[0];
        if (lim==3) c2=c1+st[m[2]].size()-cur[1];
        else c2=c1;
        ans=min(ans, c2);
        next_permutation(m, m+lim);
    }
    printf("%d", ans);
}