#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

const int N=100005;
const double pi = acos(-1.0);
struct Cir
{
  long long x,y,r;
}c[N];

struct node
{
  int id;
};

bool operator < (node o1,node o2)
{
  if (abs(o1.id)==abs(o2.id)) return o1.id<o2.id;
  Cir c1=c[abs(o1.id)],c2=c[abs(o2.id)];
  if ((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y)>(c1.r+c2.r)*(c1.r+c2.r))
    return c1.y<c2.y;
  long long p1=c1.y+c1.r*o1.id/abs(o1.id);
  long long p2=c2.y+c2.r*o2.id/abs(o2.id);
  if(p1!=p2)return p1<p2;
  if(o1.id>0&&o2.id>0){
    return c1.r<c2.r;
  }else if(o1.id<0&&o2.id<0){
    return c1.r>c2.r;
  }else if(o1.id<0&&o2.id>0){
    return 0;
  }else return 1;
}


bool cmp(int o1,int o2)
{
  long long p1=c[abs(o1)].x-c[abs(o1)].r*(long long) (abs(o1)/o1);
  long long p2=c[abs(o2)].x-c[abs(o2)].r*(long long) (abs(o2)/o2);
  if(p1!=p2)return p1<p2;
  if(o1>0&&o2>0){
    return c[o1].r>c[o2].r;
  }else if(o1<0&&o2<0){
    return c[-o1].r<c[-o2].r;
  }else if(o1<0&&o2>0){
    return 1;
  }else{
    return 0;
  }
  //  return (p1<p2)||((p1==p2)&&(o1<o2));
}

set <node> s;
set <node>::iterator it;
int n,fir[N],tot,b[N*2],fa[N];
long long f[N][2][2], ans;

struct Edge
{
  int to,nxt;
}edge[N];

void addedge(int x,int y)
{
  edge[tot]=(Edge) {y,fir[x]}; fir[x]=tot++;
}


void dp(int x){
  f[x][0][1]=f[x][0][0]=c[x].r*c[x].r;
  f[x][1][1]=f[x][1][0]=-c[x].r*c[x].r;
  for (int i=fir[x]; i!=-1; i=edge[i].nxt){
    dp(edge[i].to);
    f[x][0][1]+=max(f[edge[i].to][1][1],f[edge[i].to][0][0]);
    f[x][0][0]+=max(f[edge[i].to][1][0],f[edge[i].to][1][0]);
    f[x][1][1]+=max(f[edge[i].to][0][1],f[edge[i].to][0][1]);
    f[x][1][0]+=max(f[edge[i].to][0][0],f[edge[i].to][1][1]);
  }
}
int main()
{
  scanf("%d",&n);
  for (int i=1; i<=n; i++) 
    {
      scanf("%I64d%I64d%I64d",&c[i].x,&c[i].y,&c[i].r);
      b[i]=i;
      b[i+n]=-i;
    }
  sort(b+1,b+1+2*n,cmp);
  c[n+1].x=c[n+1].y=0; c[n+1].r=1000000000;
  s.insert((node) {n+1});
  s.insert((node) {-(n+1)});
  memset(fir,-1,sizeof(fir)); tot=0;
  for (int i=1; i<=2*n; i++)
    if (b[i]>0)
      {
	it=s.upper_bound( (node) {b[i]} );
	it--;
	if ((*it).id<0) fa[b[i]]=-(*it).id; else
	  fa[b[i]]=fa[(*it).id];
	addedge(fa[b[i]],b[i]);
	s.insert( (node) {b[i]} );
	s.insert( (node) {-b[i]} );
      }
    else
      {
	s.erase( (node) {b[i]} );
	s.erase( (node) {-b[i]} );
      }
  c[n+1].r=0;
  dp(n+1);
  printf("%.8f",pi*f[n+1][1][1]);
  return 0;
}