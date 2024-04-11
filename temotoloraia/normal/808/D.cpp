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
int n,a[N];
ll s[N];
map<ll,int>M;
int main(){
   cin>>n;
   for (int i=1;i<=n;i++){
      cin>>a[i];
      s[i]=s[i-1]+a[i];
   }
   for (int i=1;i<=n;i++)M[-a[i]]++;
   for (int i=1;i<=n;i++){
      M[a[i]]++;
      M[-a[i]]--;
      if (M[(s[i]-(s[n]-s[i]))/2] && (s[i]-(s[n]-s[i]))%2==0){
         cout<<"YES"<<endl;
         return 0;
      }
   }
   cout<<"NO"<<endl;
   return 0;
}