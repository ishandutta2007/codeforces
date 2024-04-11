#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ld long double
#define f first
#define sec second

int n,m,a,b,d,sum,kol,mid,l,r,x,y;
set<int> st;
vector <int> Vec,Vec1;
string s,s1,s2;
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

struct coor
{
    int x,y;
};

struct graph
{
    int from,to,cost;
};

int lbs(int k)
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
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>a>>b;
    if (!a && !b) cout<<"NO";
    else if (a==b || a==b+1 || b==a+1) cout<<"YES";
    else cout<<"NO";


    return 0;
}