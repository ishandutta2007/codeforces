#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define MOD 1e9+7
#define N 100005
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
int n,m,l,a[100005],b[100005];
set<int>s;
int main()
{
   cin>>n>>m;
   for (int i=1;i<=n;i++)cin>>a[i];
   for (int i=n;i>=1;i--){
      s.insert(a[i]);
      b[i]=s.size();
   }
   while (m--){
      cin>>l;
      cout<<b[l]<<endl;
   }
   return 0;
}