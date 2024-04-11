#include <bits/stdc++.h>
using namespace std;
vector <int> v[2003];
int nrf[2003];
int dfs1 (int pz)
{
    nrf[pz]=1;
    for(int i=0;i<v[pz].size();++i)
    {
        dfs1(v[pz][i]);
        nrf[pz]+=nrf[v[pz][i]];
    }
}
int c[2003];
int vaux[2003];
int dfs (int pz)
{
    int vc[2003];
    int j=1;
    if(j==c[pz]+1)
        ++j;
    vc[c[pz]+1]=pz;
    for(int i=0;i<v[pz].size();++i)
    {
        dfs(v[pz][i]);
        for(int k=1;k<=nrf[v[pz][i]];++k)
        {
            vc[j++]=vaux[k];
            if(j==c[pz]+1)
                ++j;
        }
    }
    for(int i=1;i<=nrf[pz];++i)
    {
        vaux[i]=vc[i];
   //     cout<<vaux[i]<<' ';
    }
   // cout<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long root,m,n,w,t,i,j,k=0,pas=1<<15,sc=0,cnt=0,mn=1000000009,nr1=0,nr2=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        int a,b;
        cin>>a>>b;
        if(a!=0)
            v[a].push_back(i);
        else
            root=i;
        c[i]=b;
    }
    dfs1(root);
    for(i=1;i<=n;++i)
    {
        if(nrf[i]<=c[i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    dfs(root);
    for(i=1;i<=n;++i)
        c[vaux[i]]=i;
    for(i=1;i<=n;++i)
        cout<<c[i]<<' ';
    return 0;
}