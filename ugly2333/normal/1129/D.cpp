//CF1129D
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
const int N = 111111;
const int B = 444;
const int MO = 998244353;
int n,k,m,b[N],bl[N],br[N],t[N],e[N],f[N],g[233][N*2];
int p[N],q[N];
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
	if(x<0)
		x+=MO;
}
void ad1(int l,int r){
	//cout<<"AD1 "<<l<<r<<endl;
	int i,o;
	if(b[l]==b[r]){
		o=b[l];
		for(i=l;i<=r;i=i+1)
			ad(g[o][e[i]],-f[i]),e[i]++;
		return;
	}
	ad1(l,br[b[l]]),l=bl[b[l]+1];
	ad1(bl[b[r]],r),r=br[b[r]-1];
	if(l>r)
		return;
	for(i=b[l];i<=b[r];i=i+1)
		t[i]++;
}
void ad0(int l,int r){
	//cout<<"AD-1 "<<l<<r<<endl;
	int i,o;
	if(b[l]==b[r]){
		o=b[l];
		for(i=l;i<=r;i=i+1)
			e[i]--,ad(g[o][e[i]],f[i]);
		return;
	}
	ad0(l,br[b[l]]),l=bl[b[l]+1];
	ad0(bl[b[r]],r),r=br[b[r]-1];
	if(l>r)
		return;
	for(i=b[l];i<=b[r];i=i+1)
		t[i]--;
}
int qu(int r){
	int i;
	LL x=0;
	for(i=1;i<b[r];i=i+1)
		x+=g[i][k-t[i]];
	for(i=bl[b[r]];i<=r;i=i+1)
		if(e[i]+t[i]<=k)
			x+=f[i];
	return x%MO;
}
void bdg(int o){
	int i;
	for(i=0;i<N+N;i=i+1)
		g[o][i]=0;
	for(i=bl[o];i<=br[o];i=i+1)
		ad(g[o][e[i]],f[i]);
	for(i=1;i<N+N;i=i+1)
		ad(g[o][i],g[o][i-1]);
}
int main()
{
	int i,x;
	scanf("%d%d",&n,&k);
	k+=N;
	for(i=0;i<=n;i=i+1){
		if(i%B==0)
			m++,bl[m]=i;
		b[i]=m;
		br[m]=i;
		e[i]=N;
	}
	f[0]=1;
	for(i=1;i<=n;i=i+1)
		q[i]=-1,p[i]=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		ad1(p[x],i-1);
		if(q[x]>=0)
			ad0(q[x],p[x]-1);
		q[x]=p[x],p[x]=i;
		f[i]=qu(i);
		if(br[b[i]]==i)
			bdg(b[i]);
		//cout<<f[i]<<endl;
	}
	cout<<f[n];
	return 0;
}