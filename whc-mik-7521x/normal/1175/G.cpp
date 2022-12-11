#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=2e4+10,K=100,P=N*30;
const long long INF=1e18;
int n,k,a[N+5];
long long dp[N+5][K+5];
struct line{
	long long k,b;
	line(long long kk=0,long long bb=INF){k=kk,b=bb;}
	long long calc(int x){return 1ll*k*x+b;}
}lin[N*2+5];
int lcnt=0;
struct node{
	int son[2],mx;
}s[P+5];
int rt[N+5],R=0,ocnt=0,ct=0;
struct chg{
	int k,on,ori;
}op[P+5];
void add(int k,int id,int o){
	if(o)op[++ocnt]={k,o,s[k].mx};
	s[k].mx=id;
}
void ins(int &k,int l,int r,int v,int fr){
	if(!k)return k=++ct,add(k,v,fr),void();
	int mid=(l+r)>>1;
	long long l1=lin[s[k].mx].calc(l),r1=lin[s[k].mx].calc(r),m1=lin[s[k].mx].calc(mid);
	long long l2=lin[v].calc(l),r2=lin[v].calc(r),m2=lin[v].calc(mid);
	if(l1<=l2&&r1<=r2)return;
	if(l2<=l1&&r2<=r1)return add(k,v,fr);
	if(m2<=m1){
		if(l2<=l1)ins(s[k].son[1],mid+1,r,s[k].mx,fr),add(k,v,fr);
		else ins(s[k].son[0],l,mid,s[k].mx,fr),add(k,v,fr);
	}
	else{
		if(l2<=l1)ins(s[k].son[0],l,mid,v,fr);
		else ins(s[k].son[1],mid+1,r,v,fr);
	}
}
int merge(int x,int y,int l,int r){
	if(!x)return y;
	if(!y)return x;
	ins(x,l,r,s[y].mx,0);
	int mid=(l+r)>>1;
	s[x].son[0]=merge(s[x].son[0],s[y].son[0],l,mid);
	s[x].son[1]=merge(s[x].son[1],s[y].son[1],mid+1,r);
	return x;
}
long long query(int k,int l,int r,int p){
	if(!k)return INF;
	int mid=(l+r)>>1;
	if(l==r)return lin[s[k].mx].calc(p);
	return min((p<=mid)?query(s[k].son[0],l,mid,p):query(s[k].son[1],mid+1,r,p),lin[s[k].mx].calc(p));
}
int stk[N+5],tp=0;
void init(){
	memset(rt,0,sizeof(rt));
	for(int i=1;i<=ct;i++)s[i].son[0]=s[i].son[1]=s[i].mx=0;
	ct=lcnt=ocnt=tp=R=0;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(dp,63,sizeof(dp));
	dp[0][0]=0;
	for(int j=1;j<=k;j++){
		init();
		for(int i=1;i<=n;i++){
			lin[++lcnt]=line(-(i-1),dp[i-1][j-1]);
			ins(rt[i],1,M,lcnt,0);
			while(tp>0&&a[stk[tp]]<a[i]){
				while(ocnt>0&&op[ocnt].on==stk[tp])s[op[ocnt].k].mx=op[ocnt].ori,ocnt--;
				rt[i]=merge(rt[i],rt[stk[tp]],1,M);
				tp--;
			}
			lin[++lcnt]=line(a[i],query(rt[i],1,M,a[i]));
			ins(R,1,n,lcnt,i);
			dp[i][j]=query(R,1,n,i);
			stk[++tp]=i;
		}
	}
	printf("%lld\n",dp[n][k]);
	return 0;
}