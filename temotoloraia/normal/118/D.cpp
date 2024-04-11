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
const int MOD=1e8,N=105;
const ll INF=1e17;
int n1,n2,k1,k2;
int m1,m2;
ll dp1[N][N],dp2[N][N];
int main(){
   cin>>n1>>n2>>k1>>k2;
   for (int i=0;i<=k1;i++)dp1[i][0]=1;
   for (int i=0;i<=k2;i++)dp2[0][i]=1;
   for (m1=1;m1<=n1;m1++)
   for (m2=1;m2<=n2;m2++){
   for (int p1=max(m1-k1,0);p1<m1;p1++)
   dp1[m1][m2]=(dp1[m1][m2]+dp2[p1][m2])%MOD;
   for (int p2=max(m2-k2,0);p2<m2;p2++)
   dp2[m1][m2]=(dp2[m1][m2]+dp1[m1][p2])%MOD;
   }
   cout<<(dp1[n1][n2]+dp2[n1][n2])%MOD<<endl;
   return 0;
}