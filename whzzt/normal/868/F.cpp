#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005,K=25;
const ll inf=1e12;

int n,k,p[N];
ll dp[K][N],vw[N],now;
int qs,qt;

inline void del(int x){now-=--vw[x];}
inline void ins(int x){now+=vw[x]++;}

struct node{
	int l,r,s,t;
	node(int a=0,int b=0,int c=0,int d=0){
		l=a,r=b,s=c,t=d;
	}
}qu[N*10];
int ql,qr;

void solve(ll*a,ll*b,int l,int r,int s,int t){
	if(l>r)return;
	int mid=(l+r)>>1;
	while(qt<mid)qt++,ins(p[qt]);
	while(qt>mid)del(p[qt]),qt--;
	int e=min(t,mid);
	while(qs<e)del(p[qs]),qs++;
	while(qs>e)qs--,ins(p[qs]);
	int best=0;ll val=inf;
	while(qs>=s){
		ll t=b[qs-1]+now;
		if(t<val)val=t,best=qs;
		qs--,ins(p[qs]);
	}
	a[mid]=val;
	qu[++qr]=node(l,mid-1,s,best);
	qu[++qr]=node(mid+1,r,best,t);
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)dp[0][i]=inf;
	for(int i=1;i<=k;i++){
		memset(vw,0,sizeof(vw));
		now=0;qs=1,qt=0,ql=qr=1;
		qu[1]=node(1,n,1,n);
		while(ql<=qr){
			solve(dp[i],dp[i-1],qu[ql].l,qu[ql].r,qu[ql].s,qu[ql].t);
			ql++; 
		}
	}
	printf("%lld\n",dp[k][n]);
	return 0;
}