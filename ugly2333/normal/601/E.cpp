//CF601E
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
const int N = 15555;
const int W = 1111;
const int B = 1e7+19;
const int MO = 1e9+7;
int n,w,q,m,a[N],b[N],l[N],r[N];
vector<int> v[1<<17];
int f[22][W];
void modify(int L,int R,int i,int k=1,int l=1,int r=m){
	if(L<=l&&r<=R){
		v[k].push_back(i);
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,i,k<<1,l,h);
	if(h<R)
		modify(L,R,i,k<<1|1,h+1,r);
}
void go(int d,int x){
	int i;
	for(i=w;i>=b[x];i=i-1)
		f[d][i]=max(f[d][i],f[d][i-b[x]]+a[x]);
}
void solve(int k,int l,int r,int d){
	int i;
	for(i=0;i<=w;i=i+1)
		f[d][i]=f[d-1][i];
	for(i=0;i<v[k].size();i=i+1)
		go(d,v[k][i]);
	if(l==r){
		int x=0;
		for(i=w;i>=1;i=i-1)
			x=(LL)x*B%MO+f[d][i],x%=MO;
		printf("%d\n",x);
		return;
	}
	int h=l+r>>1;
	solve(k<<1,l,h,d+1);
	solve(k<<1|1,h+1,r,d+1);
}
int main()
{
	int i,x,y,z;
	scanf("%d%d",&n,&w);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",a+i,b+i);
		l[i]=1;
		r[i]=-1;
	}
	scanf("%d",&q);
	for(i=1;i<=q;i=i+1){
		scanf("%d",&z);
		if(z==3){
			m++;
			continue;
		}
		if(z==2){
			scanf("%d",&x);
			r[x]=m;
		}
		else{
			scanf("%d%d",&x,&y);
			n++;
			a[n]=x,b[n]=y;
			l[n]=m+1,r[n]=-1;
		}
	}
	for(i=1;i<=n;i=i+1){
		if(r[i]<0)
			r[i]=m;
		if(l[i]<=r[i])
			modify(l[i],r[i],i);
	}
	solve(1,1,m,1);
	return 0;
}