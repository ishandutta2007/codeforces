#include <bits/stdc++.h>.

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);;
    long long k[n+1];
    memset(k,0,sizeof(k));
    vector< vector<int> > a(n+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        k[u]++;
        k[v]++;
        a[max(u,v)].push_back(min(u,v));
    }
    long long len[n+1];
    for(int i=1;i<=n;i++)
    {
        len[i]=1;
        for(int j=0;j<a[i].size();j++)
            len[i]=max(len[i],len[a[i][j]]+1);
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,k[i]*len[i]);
    printf("%I64d",ans);
}