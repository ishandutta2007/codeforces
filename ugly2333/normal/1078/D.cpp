//CF1078D
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
int n,a[N],b[N][20],c[N][20],d[N],e[N],f[N];
int t[N<<2],s[N<<2],ql,qr,wl,wr;
void build(int j,int k=1,int l=0,int r=n-1){
	if(l==r){
		t[k]=b[l][j];
		s[k]=c[l][j];
		return;
	}
	int h=l+r>>1;
	build(j,k<<1,l,h);
	build(j,k<<1|1,h+1,r);
	t[k]=min(t[k<<1],t[k<<1|1]);
	s[k]=max(s[k<<1],s[k<<1|1]);
}
void query(int k=1,int l=0,int r=n-1){
	if(ql<=l&&r<=qr){
		if(wl>t[k])
			wl=t[k];
		if(wr<s[k])
			wr=s[k];
		return;
	}
	int h=l+r>>1;
	if(ql<=h)
		query(k<<1,l,h);
	if(h<qr)
		query(k<<1|1,h+1,r);
}
void q(int l,int r){
	ql=l,qr=r;
	query();
}
void Q(int l,int r){
	wl=N,wr=-N;
	if(l<0)
		q((l+n)%n,n-1),wl-=n,wr-=n,l=0;
	if(r>=n)
		q(0,r%n),wl+=n,wr+=n,r=n-1;
	q(l,r);
}
int main()
{
	int i,j;
	scanf("%d",&n);
	if(n==1){
		cout<<0;
		return 0;
	}
	for(i=0;i<n;i=i+1){
		scanf("%d",a+i);
		b[i][0]=i-a[i],c[i][0]=i+a[i];
		d[i]=i,e[i]=i,f[i]=0;
	}
	for(j=1;j<=18;j=j+1){
		build(j-1);
		for(i=0;i<n;i=i+1){
			Q(b[i][j-1],c[i][j-1]);
			b[i][j]=wl,c[i][j]=wr;
		}
	}
	for(j=18;j>=0;j=j-1){
		build(j);
		for(i=0;i<n;i=i+1){
			Q(d[i],e[i]);
			if(wr-wl+1<n)
				d[i]=wl,e[i]=wr,f[i]|=1<<j;
		}
	}
	for(i=0;i<n;i=i+1)
		printf("%d ",f[i]+1);
	return 0;
}