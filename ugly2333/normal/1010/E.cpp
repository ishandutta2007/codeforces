//CF1010E
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
const int E = 100000;
const int M = N*150;
int n,m,k,e[N][3],lx[N],rx[N],ly[N],ry[N],w[N],ans[N];
vector<int> v[N],q[N];
int s[3],al[3],ar[3],bl[3],br[3],t[3];
int tot,rt[N<<2],T[M],ls[M],rs[M];
int ad(int z,int k,int l=1,int r=E){
	if(!k)
		k=++tot;
	T[k]++;
	if(l==r)
		return k;
	int h=l+r>>1;
	if(z<=h)
		ls[k]=ad(z,ls[k],l,h);
	else
		rs[k]=ad(z,rs[k],h+1,r);
	return k;
}
int qu(int L,int R,int k,int l=1,int r=E){
	if(!k)
		return 0;
	if(L<=l&&r<=R)
		return T[k];
	int h=l+r>>1,s=0;
	if(L<=h)
		s+=qu(L,R,ls[k],l,h);
	if(h<R)
		s+=qu(L,R,rs[k],h+1,r);
	return s;
}
void modify(int z,int k=1,int l=1,int r=E){
	rt[k]=ad(e[z][2],rt[k]);
	if(l==r)
		return;
	int h=l+r>>1;
	if(e[z][1]<=h)
		modify(z,k<<1,l,h);
	else
		modify(z,k<<1|1,h+1,r);
}
int query(int z,int k=1,int l=1,int r=E){
	if(lx[z]<=l&&r<=rx[z])
		return qu(ly[z],ry[z],rt[k]);
	int h=l+r>>1,s=0;
	if(lx[z]<=h)
		s+=query(z,k<<1,l,h);
	if(h<rx[z])
		s+=query(z,k<<1|1,h+1,r);
	return s;
}
int main()
{
	int i,j,x,f;
	for(j=0;j<3;j=j+1)
		scanf("%d",s+j),al[j]=s[j]+1,ar[j]=0,bl[j]=1,br[j]=s[j];
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i=i+1){
		for(j=0;j<3;j=j+1){
			scanf("%d",&x);
			al[j]=min(al[j],x);
			ar[j]=max(ar[j],x);
		}
	}
	for(i=1;i<=m;i=i+1){
		f=0;
		for(j=0;j<3;j=j+1){
			scanf("%d",&x);
			e[i][j]=x;
			if(al[j]<=x&&x<=ar[j])
				f++;
		}
		if(f==3){
			cout<<"INCORRECT";
			return 0;
		}
		v[e[i][0]].push_back(i);
	}
	cout<<"CORRECT\n";
	for(i=1;i<=k;i=i+1){
		for(j=0;j<3;j=j+1)
			scanf("%d",t+j);
		x=0;
		for(j=0;j<3;j=j+1)
			if(al[j]<=t[j]&&t[j]<=ar[j])
				x++;
		if(x==3){
			ans[i]=1;
			continue;
		}
		q[min(al[0],t[0])-1].push_back(-i);
		q[max(ar[0],t[0])].push_back(i);
		lx[i]=min(al[1],t[1]);
		rx[i]=max(ar[1],t[1]);
		ly[i]=min(al[2],t[2]);
		ry[i]=max(ar[2],t[2]);
	}
	for(i=0;i<N;i=i+1){
		for(j=v[i].size();j--;)
			modify(v[i][j]);
		for(j=q[i].size();j--;){
			if(q[i][j]>0)
				w[q[i][j]]+=query(q[i][j]);
			else
				w[-q[i][j]]-=query(-q[i][j]);
		}
	}
	for(i=1;i<=k;i=i+1){
		if(ans[i])
			cout<<"OPEN\n";
		else{
			if(w[i])
				cout<<"CLOSED\n";
			else
				cout<<"UNKNOWN\n";
		}
	}
	return 0;
}