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
const int MOD=1e8,N=10005;
const ll INF=1e15;
int n,m,p[N];
int l,r,x,y;
int main(){
   cin>>n>>m;
   for (int i=1;i<=n;i++)cin>>p[i];
   while (m--){
      cin>>l>>r>>x;
      y=0;
      if (l>x || r<x){cout<<"Yes"<<endl;continue;}
      for (int i=l;i<=r;i++)
      if (p[i]<p[x])y++;
      if (y==x-l)cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
   }
   return 0;
}