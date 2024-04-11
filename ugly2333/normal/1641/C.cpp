//CF1641C
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
const int N = 1<<19;
int n,q,qt[N],ql[N],qr[N],qx[N],u[N];
int t[N],s[N],e[N],p[N];
void go(int L,int R,int X,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		t[k]=min(t[k],X);
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		go(L,R,X,k<<1,l,h);
	if(h<R)
		go(L,R,X,k<<1|1,h+1,r);
}
void dfs(int k=1,int l=1,int r=n){
	if(l==r){
		if(t[k]==q+1)
			s[k]=1,p[k]=0;
		else
			s[k]=0,p[k]=t[k];
		e[k]=s[k]*l;
		return;
	}
	t[k<<1]=min(t[k<<1],t[k]);
	t[k<<1|1]=min(t[k<<1|1],t[k]);
	int h=l+r>>1;
	dfs(k<<1,l,h);
	dfs(k<<1|1,h+1,r);
	s[k]=s[k<<1]+s[k<<1|1];
	e[k]=e[k<<1]+e[k<<1|1];
	p[k]=max(p[k<<1],p[k<<1|1]);
}
int ss,ee,pp;
void qu(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		ss+=s[k];
		ee+=e[k];
		pp=max(pp,p[k]);
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		qu(L,R,k<<1,l,h);
	if(h<R)
		qu(L,R,k<<1|1,h+1,r);
}
int main()
{
	int i;
	scanf("%d%d",&n,&q);
	for(i=0;i<N;i++)
		t[i]=q+1;
	for(i=1;i<=q;i++){
		scanf("%d",qt+i);
		if(qt[i]==0){
			scanf("%d%d%d",ql+i,qr+i,qx+i);
			if(qx[i]==0)
				go(ql[i],qr[i],i);
		}
		else
			scanf("%d",qx+i);
	}
	dfs();
	for(i=1;i<=n;i++)
		u[i]=q+1;
	for(i=1;i<=q;i++){
		if(qt[i]==0&&qx[i]==1){
			ss=0,ee=0,pp=0;
			qu(ql[i],qr[i]);
			if(ss==1)
				u[ee]=min(u[ee],max(i,pp));
		}
	}
	for(i=1;i<=q;i++){
		if(qt[i]==1){
			ss=0,ee=0,pp=0;
			qu(qx[i],qx[i]);
			if(ss==1){
				if(u[qx[i]]<i)
					printf("YES\n");
				else
					printf("N/A\n");
			}
			else{
				if(pp<i)
					printf("NO\n");
				else
					printf("N/A\n");
			}
		}
	}
	return 0;
}