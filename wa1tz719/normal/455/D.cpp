#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int sqrt_maxn=505;
deque<int> d[205];
int dp[205][100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    memset(dp,0,sizeof(dp));
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        x--;
        d[i/sqrt_maxn].push_back(x);
        dp[i/sqrt_maxn][x]++;
    }
    int q;
    scanf("%d",&q);
    int lastans=0;
    for (i=0;i<q;i++)
    {
        int oper;
        scanf("%d",&oper);
        if (oper==1)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            l=(l-1+lastans)%n;
            r=(r-1+lastans)%n;
            if (l>r) swap(l,r);
            int tl=l/sqrt_maxn;
            int tr=r/sqrt_maxn;
            if (tl==tr)
            {
                int x=d[tl][r%sqrt_maxn];
                d[tl].erase(d[tl].begin()+(r%sqrt_maxn));
                d[tl].insert(d[tl].begin()+(l%sqrt_maxn),x);
            }
            else
            {
                int x=d[tr][r%sqrt_maxn];
                d[tr].erase(d[tr].begin()+(r%sqrt_maxn));
                d[tl].insert(d[tl].begin()+(l%sqrt_maxn),x);
                dp[tr][x]--;
                dp[tl][x]++;
                int i;
                for (i=tl;i<tr;i++)
                {
                    d[i+1].push_front(d[i].back());
                    dp[i][d[i+1][0]]--;
                    dp[i+1][d[i+1][0]]++;
                    d[i].pop_back();
                    
                }
            }
        }
        else
        {
            int l,r,col;
            scanf("%d%d%d",&l,&r,&col);
            l=(l-1+lastans)%n;
            r=(r-1+lastans)%n;
            if (l>r) swap(l,r);
            col=(col-1+lastans)%n;
            int tl=l/sqrt_maxn,tr=r/sqrt_maxn;
            if (tl==tr)
            {
                int i;
                lastans=0;
                int temp=r%sqrt_maxn;
                for (i=l%sqrt_maxn;i<=temp;i++)
                {
                    if (d[tl][i]==col) lastans++;
                }
            }
            else
            {
                lastans=0;
                int i;
                for (i=l%sqrt_maxn;i<sqrt_maxn;i++)
                {
                    if (d[tl][i]==col) lastans++;
                }
                for (i=tl+1;i<tr;i++)
                {
                    lastans+=dp[i][col];
                }
                int temp=r%sqrt_maxn;
                for (i=0;i<=temp;i++)
                {
                    if (d[tr][i]==col) lastans++;
                }
            }
            printf("%d\n",lastans);
        }
    }
    return 0;
}