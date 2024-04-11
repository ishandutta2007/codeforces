#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define sec second

int rk[1001],parent[1001],n,from,to;
vector<pair<int,int> > Vec1,Vec2;

void make_set(int v)
{
    parent[v]=v;
    rk[v]=0;
}

int find_color(int v)
{
    if (parent[v]==v) return v;
    return parent[v]=find_color(parent[v]);
}

void set_color(int a,int b)
{
    a=find_color(a);
    b=find_color(b);
    if (rk[a]<rk[b]) swap(a,b);
    parent[b]=a;
    if (rk[a]==rk[b]) rk[a]++;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);

    cin>>n;
    for(int i=1;i<=n;i++) make_set(i);
    for (int i=0;i<n-1;i++)
    {
        cin>>from>>to;
        if (find_color(from)!=find_color(to))
        {
            set_color(from,to);
        }
        else Vec1.push_back(make_pair(from,to));
    }

    for (int i=1;i<=n;i++)
    for (int j=i+1;j<=n;j++)
    {
        if (find_color(i)!=find_color(j))
        {
            Vec2.push_back(make_pair(i,j));
            set_color(i,j);
        }
    }

    cout<<Vec1.size()<<endl;

    for (int i=0;i<Vec1.size();i++)
    {
        cout<<Vec1[i].f<<" "<<Vec1[i].sec<<" "<<Vec2[i].f<<" "<<Vec2[i].sec<<endl;
    }




    return 0;
}