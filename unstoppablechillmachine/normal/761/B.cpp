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
   cin>>n>>l;
   Vec.resize(n);
   Vec1.resize(n);
   for (int i=0;i<n;i++)
   {
       cin>>Vec[i];
   }

   for (int i=0;i<n;i++)
   {
       cin>>Vec1[i];
   }

   for (int i=1;i<=n;i++)
   {
       //copy(Vec.begin(),Vec.end(),ostream_iterator<int>(cout," "));
       //cout<<endl;

       //copy(Vec1.begin(),Vec1.end(),ostream_iterator<int>(cout," "));
       //cout<<endl<<endl;
       t=true;
       if (Vec[0]>Vec1[0])
       {
            a=1;
            x=Vec[0]-Vec1[0];
       }
       else
       {
           a=2;
           x=Vec1[0]-Vec[0];
       }
       //cout<<x<<endl;
       for (int j=1;j<n;j++)
       {
           if (a==2)
           {
               if (((Vec[j]+x)%l)!=Vec1[j]) t=false;
           }
           else if (a==1)
           {
               if (((Vec1[j]+x)%l)!=Vec[j]) t=false;
           }
       }

       if (t)
       {
           cout<<"YES";
           exit(0);
       }

       b=Vec1[n-1];
       Vec1.erase(Vec1.begin()+n-1);
       Vec1.insert(Vec1.begin(),b);

   }

   cout<<"NO";





    return 0;
}