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
const int MOD=1e9+7,N=100005;
const ll INF=1e11;
int n, a[N], b[N], m, type, l, r;
ll s[3][N];
int main()
{
   cin>>n;
   for (int i=1;i<=n;i++){
      cin>>a[i];
      b[i]=a[i];
      s[1][i]=s[1][i-1]+a[i];
   }
   sort(b+1,b+n+1);
   for (int i=1;i<=n;i++)
   s[2][i]=s[2][i-1]+b[i];
   cin>>m;
   while (m--){
      cin>>type>>l>>r;
      cout<<s[type][r]-s[type][l-1]<<endl;
   }
   return 0;
}