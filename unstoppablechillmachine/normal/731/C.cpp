#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define sec second

map<int,int> mp;
vector<vector<int> > un;
int from,to,n,m,k,parent[1000001],rk[1000001],c[1000001],max1,sum;

void make_set(int v)
{
    parent[v]=v;
    rk[v]=1;
}

int find_color(int v)
{
    if (parent[v]==v) return v;
    else return parent[v]=find_color(parent[v]);
}

void union_sets(int a,int b)
{
    a=find_color(a);
    b=find_color(b);
    if (a==b) return;
    if (rk[a]<rk[b]) swap(a,b);
    parent[b]=a;
    if (rk[a]==rk[b]) rk[a]++;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);

    cin>>n>>m>>k;
    un.resize(1000001);
    for (int i=1;i<=n;i++)
    {
        cin>>c[i];
        make_set(i);
    }

    for (int i=0;i<m;i++)
    {
        cin>>from>>to;
        union_sets(from,to);
    }

    for (int i=1;i<=n;i++)
    {
        un[find_color(i)].push_back(i);
    }

    for (int i=0;i<un.size();i++)
    {
        max1=0;
        mp.clear();
        for (int j=0;j<un[i].size();j++)
        {
            mp[c[un[i][j]]]++;
        }
        for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            max1=max(max1,(*it).sec);
        }
        sum+=un[i].size()-max1;
    }

    cout<<sum;

    return 0;
}