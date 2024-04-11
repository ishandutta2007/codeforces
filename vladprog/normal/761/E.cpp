#include<bits/stdc++.h>

using namespace std;

vector< vector<long long> > a;
vector< pair<long long,long long> > k;
vector<long long> power;

const pair<long long,long long> d[4]={{1,0},{0,1},{-1,0},{0,-1}};

void dfs(long long v,long long p,long long g)
{
    for(long long i=0,j=0;i<a[v].size();i++,j++)
    {
        if(a[v][i]==p)
        {
            j--;
            continue;
        }
        if(k[p]==pair<long long,long long>(k[v].first+d[j].first*power[g+1],k[v].second+d[j].second*power[g+1]))
            j++;
        k[a[v][i]]=pair<long long,long long>(k[v].first+d[j].first*power[g],k[v].second+d[j].second*power[g]);
        dfs(a[v][i],v,g-1);
    }
}

main()
{
    long long n;
    scanf("%I64d",&n);
    a.resize(n);
    for(long long i=1;i<n;i++)
    {
        long long u,v;
        scanf("%I64d%I64d",&u,&v);
        u--;
        v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(long long i=0;i<n;i++)
        if(a[i].size()>4)
            printf("NO\n"),exit(0);
    k.resize(n);
    power.push_back(1);
    for(long long i=1;i<n;i++)
        power.push_back(power[i-1]*2);
    dfs(0,-1,n-2);
    printf("YES\n");
    for(long long i=0;i<n;i++)
        printf("%I64d %I64d\n",k[i].first,k[i].second);
}