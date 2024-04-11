#include<bits/stdc++.h>

using namespace std;

const int inf=2e9+1;

int main()
{
    map< int,pair<int,int> > g;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        g[t].first++;
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int t;
        scanf("%d",&t);
        g[t].second++;
    }
    int sa=0,sb=0,tsa=0,tsb=0;
    for(map< int, pair<int,int> >::reverse_iterator
        i=g.rbegin();
        i!=g.rend();i++)
        {
            tsa+=i->second.first;
            tsb+=i->second.second;
            if(tsa-tsb>=sa-sb)
                sa=tsa,sb=tsb;
        }
    printf("%d:%d",sa+2*n,sb+2*m);
}