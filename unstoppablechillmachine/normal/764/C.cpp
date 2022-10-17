#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ld long double
#define f first
#define sec second


int n,m,a[300000],c[300000],b,d,mid,l,r,x,y,last_used,z,sum,from,to,j;
set<int> st;
vector <vector <int> > Vec;
vector<pair<int,int> > p;
string s[10001],s1,s2;
queue <int> q;
bool t,used[100001],t1,t2;
stringstream str;

/*void dfs(int v)
{
    used[v]=1;
    for (int i=0;i<Vec[v].size();i++) if (!used[Vec[v][i]) dfs(Vec[v][i]);
    used[v]=2;
}*/



struct graph
{
    int from,to,cost;
};

/*int lbs(int k)
{
    l=-1;
    r=n-1;
    while (r-l-1)
    {
        mid=(r+l)/2;
        if (Vec[mid]>=k) r=mid;
        else l=mid;
    }
    if (Vec[r]==k) return r+1;
    else return 0;
}

int rbs(int k)
{
    l=0;
    r=n;
    while (r-l-1)
    {
        mid=(r+l)/2;
        if (Vec[mid]<=k) l=mid;
        else r=mid;
    }
    if (Vec[l]==k) return l+1;
    else return 0;
}*/



void dfs(int v,int from)
{
    for (int i=0;i<Vec[v].size();i++)
    {
        if (Vec[v][i]!=from)
        {
            if (c[Vec[v][i]]==c[v]) dfs(Vec[v][i],v);
            else t2=false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    Vec.resize(n+1);
    for (int i=1;i<=n-1;i++)
    {
        cin>>from>>to;
        Vec[from].push_back(to);
        Vec[to].push_back(from);
        p.push_back(make_pair(from,to));
    }

    for(int i=1;i<=n;i++) cin>>c[i];
    while (j<n-1)
    {
        if (c[p[j].f]!=c[p[j].sec])
        {
            t1=true;
            break;
        }
        j++;
    }
    if (!t1)
    {
        cout<<"YES"<<endl<<n;
        exit(0);
    }
    x=p[j].f;
    t1=true;
    t2=true;
    for (int i=0;i<n-1;i++)
    {
        if (c[p[i].f]!=c[p[i].sec])
        {
            if (p[i].f!=x && p[i].sec!=x)
            {
                t1=false;
                break;
            }
        }
    }
    if (t1)
    {
        for (int i=0;i<Vec[x].size();i++)
        {
            dfs(Vec[x][i],x);
        }
        if (t2)
        {
            cout<<"YES"<<endl<<x;
            exit(0);
        }
    }



    x=p[j].sec;
    t1=true;
    t2=true;
    for (int i=0;i<n-1;i++)
    {
        if (c[p[i].f]!=c[p[i].sec])
        {
            if (p[i].f!=x && p[i].sec!=x)
            {
                t1=false;
                break;
            }
        }
    }
    if (t1)
    {
        for (int i=0;i<Vec[x].size();i++)
        {
            dfs(Vec[x][i],x);
        }
        if (t2)
        {
            cout<<"YES"<<endl<<x;
            exit(0);
        }
    }

    cout<<"NO";

    return 0;
}