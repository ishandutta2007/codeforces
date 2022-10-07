#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=105;
const ll INF=1e11;
int n, m, a[N][N], b[N*N], d, start, mid, ans;
vector<int>v;
int main()
{
   cin>>n>>m>>d;
   for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++){
   cin>>a[i][j];
   b[a[i][j]]++;
   v.push_back(a[i][j]);
   }
   for (int i=1;i<=10000;i++)
   if (b[i]){
      if (start && (i-start)%d){cout<<-1<<endl;return 0;}
      if (start==0)start=i;
   }
   sort(v.begin(),v.end());
   mid=v[n*m/2];
   for (int i=start;i<=10000;i+=d)ans+=abs(mid-i)/d*b[i];
   cout<<ans<<endl;
   return 0;
}