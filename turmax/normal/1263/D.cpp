#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> parent;
vector <int> lp;
int get(int x)
{
    int y=x;
    while(true)
    {
       if(parent[y]==(-1))
       {
           return y;
       }
       y=parent[y];
    }
}
void merg(int x,int y)
{
    //out<<x<<" "<<y<<endl;
    x=get(x);
    y=get(y);
    //cout<<x<<" "<<y<<endl;
    if(x==y)
    {
        return;
    }
    if(lp[x]>=lp[y])
    {
        parent[y]=x;
        lp[x]+=lp[y];
    }
    else
    {
        parent[x]=y;
        lp[y]+=lp[x];
    }
}
bool h[210000][26];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <string> a(n);
    parent.resize(n);
    lp.resize(n);
    vector <int> v[26];
    for(int i=0;i<n;++i)
    {
        parent[i]=(-1);
        lp[i]=1;
    }
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        for(int j=0;j<a[i].size();++j)
        {
            h[i][a[i][j]-'a']=true;
            v[a[i][j]-'a'].push_back(i);
        }
    }
    for(int i=0;i<26;++i)
    {
        for(int j=1;j<v[i].size();++j)
        {
            merg(v[i][j],v[i][j-1]);
        }
    }
    set <int> o;
    for(int i=0;i<n;++i)
    {
        o.insert(get(i));
    }
    cout<<o.size();
    return 0;
}