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
const ll MOD=1e9+7,N=2105;
const ll INF=1e11;
int n,k,sum;
int main(){
   cin>>n;
   for (k=1;k<=n;k++)
   if (k*(k+1)/2>n)break;
   k--;
   cout<<k<<endl;
   for (int i=1;i<k;i++)cout<<i<<" ";
   cout<<n-k*(k-1)/2<<endl;
   return 0;
}