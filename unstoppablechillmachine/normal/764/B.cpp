#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ld long double
#define f first
#define sec second

struct abt
{
    int first,second,kol;
};

int n,m,a[300000],b,d,mid,l,r,x,y,last_used,z,sum;
set<int> st;
vector <abt> Vec;
vector<int> Vec1;
string s[10001],s1,s2;
queue <int> q;
bool t,used[100001];
pair<int,int> p;
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

bool cmp(abt a,abt b)
{
    return a.sec>b.sec;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for (int i=1;i<=n-i+1;i++)
    {
        if (i%2==1) swap(a[i],a[n-i+1]);
    }

    for (int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}