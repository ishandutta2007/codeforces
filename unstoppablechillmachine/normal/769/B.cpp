#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ld long double
#define f first
#define sec second

typedef long long ll;

ll n,sum,fr[1001];
vector<pair<int,int> > Vec,Vec1;

void dfs(int v)
{
    for (int i=0;i<Vec[v].f;i++)
    {
        if (sum==n-1)  return;
        sum++;
        Vec1.push_back(make_pair(Vec[v].sec,Vec[sum].sec));
    }
    if (sum<n-1 && sum>=v+1) dfs(v+1);
}

bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.f>b.f;
}

int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   cin>>n;
   Vec.resize(n);
   for (int i=0;i<n;i++)
   {
       cin>>Vec[i].f;
       Vec[i].sec=i;
   }

   sort(Vec.begin()+1,Vec.end(),cmp);

   //for (int i=0;i<n;i++) cout<<Vec[i].f<<" "<<Vec[i].sec<<endl;

   dfs(0);

   if (sum<n-1)
   {
       cout<<-1;
       exit(0);
   }

   cout<<n-1<<endl;
   for (int i=0;i<Vec1.size();i++)
   {
       cout<<Vec1[i].f+1<<" "<<Vec1[i].sec+1<<endl;
   }

   return 0;
}