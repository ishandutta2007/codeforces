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
const int MOD=1e9+7,N=505;
const ll INF=1e11;
int n, m, q;
int r1,r2,c1,c2;
int dpr[N][N],dpc[N][N];
int ans;
char ch[N][N];
int main()
{
   cin>>n>>m;
   for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
   cin>>ch[i][j];
   for (int i=2;i<=n;i++)
   for (int j=1;j<=m;j++){
      dpc[i][j]=dpc[i-1][j];
      if (ch[i][j]=='.' && ch[i-1][j]=='.')dpc[i][j]++;
   }
   for (int i=1;i<=n;i++)
   for (int j=2;j<=m;j++){
      dpr[i][j]=dpr[i][j-1];
      if (ch[i][j]=='.' && ch[i][j-1]=='.')dpr[i][j]++;
   }
   cin>>q;
   while (q--){
      ans=0;
      cin>>r1>>c1>>r2>>c2;
      for (int i=r1;i<=r2;i++)
      ans+=dpr[i][c2]-dpr[i][c1];
      for (int i=c1;i<=c2;i++)
      ans+=dpc[r2][i]-dpc[r1][i];
      cout<<ans<<endl;
   }
   return 0;
}