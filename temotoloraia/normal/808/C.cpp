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
int n,w,a[N],I,X,mas[N];
pair<int,int>P[N];
int main(){
   cin>>n>>w;
   for (int i=1;i<=n;i++){
      cin>>P[i].fr;
      P[i].sc=i;
      w-=(P[i].fr+1)/2;
   }
   if (w<0){cout<<-1;return 0;}
   sort(P+1,P+n+1);
   for (int i=1;i<=n;i++)a[i]=P[i].fr;
   for (int i=n;i>=1;i--){
      X=min(w,a[i]-(a[i]+1)/2);
      P[i].fr=X+(a[i]+1)/2;
      w-=X;
   }
   for (int i=1;i<=n;i++)
   mas[P[i].sc]=P[i].fr;
   for (int i=1;i<=n;i++)cout<<mas[i]<<" ";
   return 0;
}