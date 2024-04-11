#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define sec second

int parent[1000001],n,m,q,a,b,t;
string s,s1,s2;
map<string,int> mp;

void make_set(int v)
{
    parent[v]=v;
}

int find_color(int v)
{
    if (parent[v]==v) return v;
    else return parent[v]=find_color(parent[v]);
}

void union_sets(int a,int b)
{
    if (t==1)
    {
        parent[b]=a;
        if (b%2==0)
        {
            if (a%2==1) parent[b-1]=a+1;
            else parent[b-1]=a-1;
        }
        else
        {
            if (a%2==1) parent[b+1]=a+1;
            else parent[b+1]=a-1;
        }
    }
    else
    {
        if (a%2==1) parent[b]=a+1;
        else parent[b]=a-1;

        if (b%2==0) parent[b-1]=a;
        else parent[b+1]=a;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);

    cin>>n>>m>>q;
    for (int i=0;i<n;i++)
    {
        cin>>s;
        make_set(i*2+1);
        make_set((i+1)*2);
        mp[s]=i;
    }

    for (int i=0;i<m;i++)
    {
        cin>>t>>s1>>s2;
        a=find_color(mp[s1]*2+1);
        b=find_color(mp[s2]*2+1);
        if (a>b) swap(a,b);
        if (t==1)
        {
            if (b-a!=1 || (b%2==1 && b-a==1))
            {
                union_sets(a,b);
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
        else
        {
            if (a!=b)
            {
                union_sets(a,b);
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }

    for (int i=0;i<q;i++)
    {
        cin>>s1>>s2;
        a=find_color(mp[s1]*2+1);
        b=find_color(mp[s2]*2+1);
        if (a>b) swap(a,b);
        if (a==b) cout<<1<<endl;
        else if (b-a==1 && b%2==0) cout<<2<<endl;
        else cout<<3<<endl;

    }
    return 0;
}