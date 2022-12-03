#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<sstream>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[500005];
const int block=512;
const int max_block=500000/block+1;
int delta[max_block];
multiset<int> s[max_block];
const int maxint=1000000007;
int query(int x)
{
    int i;
    for (i=0;i<max_block;i++)
    {
        if (s[i].find(x-delta[i])!=s[i].end()) break;
    }
    if (i==max_block) return -1;
    int t=i*block;
    int j;
    for (j=t;j<t+block;j++)
    {
        if (a[j]+delta[i]==x) break;
    }
    int minl=j;
    for (i=max_block-1;i>=0;i--)
    {
        if (s[i].find(x-delta[i])!=s[i].end()) break;
    }
    t=i*block;
    for (j=t+block-1;j>=t;j--)
    {
        if (a[j]+delta[i]==x) break;
    }
    int maxr=j;
    return maxr-minl;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,q;
    scanf("%d%d",&n,&q);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s[i/block].insert(a[i]);
    }
    for (i=0;i<q;i++)
    {
        int oper;
        scanf("%d",&oper);
        if (oper==1)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            l--;
            int x;
            scanf("%d",&x);
            int t;
            t=l/block;
            for (;l<r;)
            {
                if (l==(t+1)*block) break;
                s[t].erase(s[t].lower_bound(a[l]));
                a[l]+=x;
                if (a[l]>=maxint) a[l]=maxint;
                s[t].insert(a[l]);
                l++;
            }
            t=r/block;
            for (;l<r;)
            {
                if (r==t*block) break;
                r--;
                s[t].erase(s[t].lower_bound(a[r]));
                a[r]+=x;
                if (a[r]>=maxint) a[r]=maxint;
                s[t].insert(a[r]);
            }
            t=l/block;
            for (;l<r;)
            {
                delta[t]+=x;
                if (delta[t]>=maxint) delta[t]=maxint;
                l+=block;
                t++;
            }
        }
        else
        {
            int x;
            scanf("%d",&x);
            printf("%d\n",query(x));
        }
    }
    return 0;
}