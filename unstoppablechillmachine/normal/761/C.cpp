#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ld long double
#define f first
#define sec second

struct len
{
    long long l1,l2,l3;
};

long long n,m,a,b,d,sum=1e9,kol,mid,l,r,x,y;
set<int> st;
vector <len> Vec,Vec1;
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

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   cin>>n>>m;
   Vec.resize(n+1);
   for (int i=1;i<=n;i++)
   {
       Vec[i].l1=1e9;
       Vec[i].l2=1e9;
       Vec[i].l3=1e9;
   }

   for (int i=1;i<=n;i++) cin>>s[i];

   for (long long i=1;i<=n;i++)
   {
       for (long long j=0;j<m;j++)
       {
           if (s[i][j]>='0' && s[i][j]<='9') Vec[i].l1=min(Vec[i].l1,min(j,m-j));
           if (s[i][j]>='a' && s[i][j]<='z') Vec[i].l2=min(Vec[i].l2,min(j,m-j));
           if (s[i][j]=='#' || s[i][j]=='*' || s[i][j]=='&') Vec[i].l3=min(Vec[i].l3,min(j,m-j));
       }
   }

   //for (int i=1;i<=n;i++) cout<<Vec[i].l1<<" "<<Vec[i].l2<<" "<<Vec[i].l3<<endl;

   for (int i=1;i<=n;i++)
   for (int j=1;j<=n;j++)
   for (int i1=1;i1<=n;i1++)
   {
       if (i==j || i==i1 || i1==j) continue;
       sum=min(sum,Vec[i].l1+Vec[j].l2+Vec[i1].l3);
   }

   cout<<sum;



    return 0;
}