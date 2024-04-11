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
const int MOD=1e8,N=100005;
const ll INF=1e15;
ll n,k,a,s[N];
ll mas[1000],np;
ll ans;
map<ll,ll>M;
int main(){
   cin>>n>>k;
   M[0]++;
   for (int i=1;i<=n;i++){
      cin>>a;
      s[i]=s[i-1]+a;
      M[s[i]]++;
   }
   mas[0]=1;
   for (int i=1;!(mas[i-1]==k && i>2) && mas[i-1]<=INF && mas[i-1]>=-INF;i++){
      mas[i]=mas[i-1]*k;
      np=i;
   }
   if (k==-1)np=1;
   if (k==1)np=0;
   for (int i=0;i<n;i++){
      for (int j=0;j<=np;j++)
         ans+=M[s[i]+mas[j]];
      M[s[i]]--;
   }
   cout<<ans<<endl;
   return 0;
}