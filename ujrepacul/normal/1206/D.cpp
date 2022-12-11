#include <bits/stdc++.h>
using namespace std;
long long vi[100005];
vector <int> v[205];
int fv[100];
int mat[205][205];
int q[205];
int dst[205];
int bfs (int a, int b)
{
    int st=1,dr=1,i,j;
    q[dr]=a;
    for(i=1;i<=200;++i)
        dst[i]=-1;
    dst[a]=0;
    while(st<=dr && q[st]!=b)
    {
        int pz=q[st];
        for(i=0;i<v[pz].size();++i)
        {
            if(mat[pz][v[pz][i]])
                continue;
            int nou=v[pz][i];
            if(dst[nou]==-1)
                dst[nou]=dst[pz]+1,q[++dr]=nou;
        }
        ++st;
    }
    return dst[b];
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,m,i,j,mx1=0,mx2=0,s=0,cntm1=0,cnt1=0,cnt0=0;
    cin>>n;
    j=0;
    for(i=1;i<=n;++i)
    {
        long long a;
        cin>>a;
        if(a)
            vi[++j]=a;
    }
    n=j;
    if(n>200)
    {
        cout<<3;
        return 0;
    }
    for(i=1;i<=n;++i)
        for(j=i+1;j<=n;++j)
            if(i!=j && (vi[i]&vi[j])!=0)
                v[i].push_back(j),v[j].push_back(i);
    for(i=1;i<=n;++i)
    {
        int j=0;
        while(vi[i])
        {
            fv[j]+=vi[i]&1;
            vi[i]>>=1;
            ++j;
        }
    }
    for(i=1;i<=90;++i)
        if(fv[i]>=3)
        {
            cout<<3;
            return 0;
        }
    int mn=999999;
    for(i=1;i<=n;++i)
    {
        for(j=0;j<v[i].size();++j)
        {
            mat[i][v[i][j]]=mat[v[i][j]][i]=1;
            int a=bfs(i,v[i][j]);
            mat[i][v[i][j]]=mat[v[i][j]][i]=0;
            if(a!=-1)
                mn=min(mn,a+1);
        }
    }
    if(mn!=999999)
        cout<<mn;
    else
        cout<<-1;
	return 0;
}