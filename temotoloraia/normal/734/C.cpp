#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const long long N=200005;
long long n,m,k,x,s,c[N],d[N];
pair<long long,long long>P[N];
long long r;
long long price[N],vel[N];
long long ans;
long long pas;
vector<long long>v1,v2;
int main() {
   cin>>n>>m>>k>>x>>s;
   for (int i=1;i<=m;i++)cin>>P[i].s;
   for (int i=1;i<=m;i++)cin>>P[i].f;
   for (int i=1;i<=k;i++)cin>>c[i];
   for (int i=1;i<=k;i++)cin>>d[i];
   sort(P+1,P+m+1);
   v1.push_back(P[1].f);
   v2.push_back(P[1].s);
   for (int i=2;i<=m;i++)
   if (P[i].s<v2[v2.size()-1])
   v1.push_back(P[i].f),v2.push_back(P[i].s);
   m=v1.size();
   for (int i=1;i<=m;i++)price[i]=v1[i-1],vel[i]=v2[i-1];
   for (int i=1;i<=m;i++)vel[i]=min(vel[i],x);
   r=m;
   while (price[r]>s && r>0)r--;
   vel[0]=x;
   ans=vel[r]*n;
   //cout<<r<<" "<<ans<<endl;
   r=k;
   for (int i=0;i<=m && price[i]<=s;i++){
      while (price[i]+d[r]>s && r>0)r--;
      if (r==0)break;
      pas=0;
      if (pas<n-c[r])pas=n-c[r];
      pas*=vel[i];
      if (pas<ans && pas>=0)ans=pas;
   }
   cout<<ans<<endl;
	return 0;
}