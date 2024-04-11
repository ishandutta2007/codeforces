#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
const int N=500005;
struct node{
  ll a,t;
}p[N];
multiset<ll,greater<ll>>cost;
ll total,ans=0;
int n;
int main(){
  n=read();
  for(int i=1;i<=n;i++)p[i].a=read();
  for(int i=1;i<=n;i++)p[i].t=read();
  sort(p+1,p+n+1,[&](node x,node y){
    return x.a<y.a;
  });
  ll cur=1,A=0;
  while(cur<=n||!cost.empty()){
    A++;
    if(cost.empty())A=p[cur].a;
    while(cur<=n&&p[cur].a==A){
      cost.insert(p[cur].t);
      total+=p[cur].t;
      cur++;
    }
    total-=*cost.begin();
    ans+=total;
    //printf("A=%lld,total=%lld\n",A,total);
    cost.erase(cost.begin());
  }
  printf("%lld\n",ans);
  return 0;
}