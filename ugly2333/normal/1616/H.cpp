//CF1616H
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 155555;
const int M = N*32;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int n,m=30,p,s,p2[N],tot,rt,ls[M],rs[M],t[M];
void ins(int&k,int x,int o=m-1){
	if(!k)
		k=++tot;
	t[k]++;
	if(o<0)
		return;
	if(x&(1<<o))
		ins(rs[k],x,o-1);
	else
		ins(ls[k],x,o-1);
}
int solve(int k1,int k2,int o){//cout<<k1<<' '<<k2<<' '<<o<<endl;
	if(!k1||!k2||o<0)
		return p2[t[k1]+t[k2]];
	if(p&(1<<o)){
		int x=solve(ls[k1],rs[k2],o-1),y=solve(rs[k1],ls[k2],o-1);
		return mul(x,y);
	}
	else{
		int x=solve(ls[k1],ls[k2],o-1),y=solve(rs[k1],rs[k2],o-1);
		ad(x,y-1);
		ad(x,mul(p2[t[ls[k1]]]-1,p2[t[rs[k1]]]-1));
		ad(x,mul(p2[t[ls[k2]]]-1,p2[t[rs[k2]]]-1));
		return x;
	}
}
void dfs(int k,int o=m-1){
	if(!k)
		return;
	if(p==0&&o<0)
		ad(s,p2[t[k]]-1);
	if(o<0)
		return;
	if(p&(1<<o)){
		ad(s,solve(ls[k],rs[k],o-1)-1);
		return;
	}
	dfs(ls[k],o-1);
	dfs(rs[k],o-1);
}
int main()
{
	int i,x;
	scanf("%d%d",&n,&p);
	p2[0]=1;
	for(i=1;i<=n;i++)
		p2[i]=mul(p2[i-1],2);
	for(i=1;i<=n;i++)
		scanf("%d",&x),ins(rt,x);
	dfs(rt);
	printf("%d\n",s);
	return 0;
}