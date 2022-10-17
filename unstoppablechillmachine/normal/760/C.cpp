#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ld long double
#define ll long long
#define f first
#define sec second

struct coor
{
    int x,y;
};

struct graph
{
    int from,to,cost;
};


bool t,used[300000];
queue <int> q;
set<int> st;
string s;
char ch;
vector <int> Vec;
int a[300000],kol,m,sum,day,ans,n,d;

void dfs(int v)
{
    used[v]=1;
    if (!used[a[v]])
    {
        dfs(a[v]);
    }
    else if (used[a[v]]==1) sum++;
    used[v]=2;
}


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf ("%d",&a[i]);
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&d);
        if (d==1) kol++;
    }
    if (kol%2==0) ans++;
    //cout<<kol<<endl;

    for (int i=1;i<=n;i++)
    {
        if (!used[i])
        {
            dfs(i);
        }
    }
    //cout<<sum<<endl;
    if (sum==1) cout<<ans;
    else cout<<ans+sum;

    return 0;
}