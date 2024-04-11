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
const int MOD=1e8,N=200005;
const ll INF=1e15;
int n,k,a[N];
ll s[N];
double ans;
int main(){
   cin>>n>>k;
   for (int i=1;i<=n;i++){
      cin>>a[i];
      s[i]=s[i-1]+a[i];
   }
   double nn=n,kk=k;
   for (int i=1;i+k-1<=n;i++)ans+=(s[i+k-1]-s[i-1]);
   printf("%.6lf",ans/(nn-kk+1));
   return 0;
}