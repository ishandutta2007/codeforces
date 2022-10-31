#include<set>
#include<map>
#include<list>
#include<queue>
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
int p[300005];
char col[300005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    char c[15];
    for (i=0;i<n;i++)
    {
        int x;
        scanf("%d%s",&x,c);
        col[i]=c[0];
        p[i]=x;
    }
    int last_g=-1000000000;
    int redcnt=0;
    int bluecnt=0;
    int last_b=-1000000000;
    int last_r=-1000000000;
    long long ans=0;
    for (i=0;i<n;i++)
    {
        if (col[i]=='G')
        {
            bluecnt=max(bluecnt,p[i]-last_b);
            redcnt=max(redcnt,p[i]-last_r);
            ans+=min((long long)(p[i]-last_g)*2,(long long)(p[i]-last_g)*3-bluecnt-redcnt);
            if (last_g<0)
            {
                ans-=p[i]-last_g;
            }
            last_b=p[i];
            last_r=p[i];
            last_g=p[i];
            redcnt=0;
            bluecnt=0;
        }
        else if (col[i]=='R')
        {
            redcnt=max(redcnt,p[i]-last_r);
            last_r=p[i];
        }
        else if (col[i]=='B')
        {
            bluecnt=max(bluecnt,p[i]-last_b);
            last_b=p[i];
        }
    }
    if (last_g<0)
    {
        //no_g
        for (i=0;i<n;i++)
        {
            if (col[i]=='B') break;
        }
        if (i!=n)
        {
            ans+=last_b-p[i];
        }
        for (i=0;i<n;i++)
        {
            if (col[i]=='R') break;
        }
        if (i!=n)
        {
            ans+=last_r-p[i];
        }
    }
    else
    {
        ans+=last_r-last_g;
        ans+=last_b-last_g;
    }
    cout<<ans<<endl;
    return 0;
}