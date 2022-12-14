#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define ll long long
#define mod 1000000007
struct node{int to,next,val;}e[N<<1];
int head[N],cnt,d[N],n,Q;
inline void add(int x,int y,int z){e[cnt]=(node){y,head[x],z};head[x]=cnt++;d[x]++;}
inline int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
struct Segment
{
	int k,b;
	Segment(){}
	Segment(int x,int y){k=x,b=y;}
	Segment operator + (const Segment &a) const {return Segment((k+a.k)%mod,(b+a.b)%mod);}
	Segment operator + (const int &a) const {return Segment(k,(b+a)%mod);}
	Segment operator * (const int &a) const {return Segment((ll)k*a%mod,(ll)b*a%mod);}
};
Segment dfs(int x,int from)
{
	if(d[x]==1&&from!=-1)return Segment(0,0);Segment ret=Segment(0,0);
	for(int i=head[x];i!=-1;i=e[i].next)
		if(e[i].to!=from)
			ret=ret+(dfs(e[i].to,x)+e[i].val)*q_pow(d[x],mod-2);
		else ret=ret+((ll)e[i].val*q_pow(d[x],mod-2)%mod);
	int inv=q_pow(1-ret.k+mod,mod-2);
	return Segment((ll)inv*q_pow(d[x],mod-2)%mod,(ll)inv*ret.b%mod);
}
int main()
{
	scanf("%d",&n);memset(head,-1,sizeof(head));
	for(int i=1,x,y,z;i<n;i++)scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	printf("%d\n",dfs(0,-1).b);
	return 0;
}