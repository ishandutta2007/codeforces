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
const int MOD=1e9+7,N=5000005;
const ll INF=1e11;
int n,k,x;
int main(){
   cin>>n>>k;
   k=240-k;
   while (5*x*(x+1)/2<=k)x++;
   x--;
   cout<<min(n,x)<<endl;
   return 0;
}