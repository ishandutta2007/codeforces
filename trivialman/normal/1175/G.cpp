#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
const int N = 2e4+5;
const int inf = 0x3f3f3f3f;
 
struct node{
	int K,B;
	node(int a=0,int b=0){K=a,B=b;}
	int get(int x){return K*x+B;}
}sta[N];
inline bool cmp(const node &a,const node &b,const node &c){return 1ll*(a.K-b.K)*(c.B-a.B)<=1ll*(a.K-c.K)*(b.B-a.B);}
int n,K,top,a[N],f[N],g[N],pmx[N],smx[N];
void insert(node x){
	//when K same, take the smallest B 
	while(top&&x.K==sta[top].K)x.B=min(x.B,sta[top].B),top--;
	while(top>1&&cmp(sta[top-1],sta[top],x))top--;sta[++top]=x;
}
int get(int x){
	if(!top)return inf;
	int l=1,r=top;
	while(l<r)	{
		int m=(l+r)>>1;
		if(sta[m].get(x)<=sta[m+1].get(x))r=m;else l=m+1;
	}
	return sta[l].get(x);
}
void solve(int l,int r){
	if(l==r)return ;int m=(l+r)>>1;solve(l,m),solve(m+1,r);
	//update when the last segment of [1,r] begins between [l,m]
	smx[m+1]=0;rrep(i,m,l)smx[i]=max(smx[i+1],a[i]);
	pmx[m]=0;rep(i,m+1,r)pmx[i]=max(pmx[i-1],a[i]);
	//maxi <= m
	top=0;int p=l;
	rrep(i,r,m+1){
		for(;p<=m&&smx[p+1]>=pmx[i];++p)
			if(g[p]<inf)insert(node(smx[p+1],g[p]-p*smx[p+1]));
		f[i]=min(f[i],get(i));
	}
	//maxi > m
	top=0;p=m;
	rep(i,m+1,r){
		for(;p>=l&&smx[p+1]<=pmx[i];--p)
			if(g[p]<inf)insert(node(p,g[p]));
		f[i]=min(f[i],get(-pmx[i])+i*pmx[i]);
	}
}
 
int main(){
	scanf("%d%d",&n,&K);
	rep(i,1,n)scanf("%d",&a[i]),pmx[i]=max(pmx[i-1],a[i]);
	rep(i,1,n)f[i]=pmx[i]*i;
	rep(i,2,K)memcpy(g,f,sizeof(g)),memset(f,0x3f,sizeof(f)),solve(1,n);
	printf("%d\n",f[n]);
}