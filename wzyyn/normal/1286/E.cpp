#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=600005;
int v[N],nxt[N],q[N];
int tg[N*4],S[N*4];
ll ans,sum[N*4];
vector<int> e[N];
char s[N];
void pushdown(int k){
	if (tg[k]==-1) return;
	tg[k*2]=tg[k*2+1]=tg[k];
	sum[k*2]=1ll*S[k*2]*tg[k];
	sum[k*2+1]=1ll*S[k*2+1]*tg[k];
	tg[k]=-1;
}
void pushup(int k){
	S[k]=S[k*2]+S[k*2+1];
	sum[k]=sum[k*2]+sum[k*2+1];
}
void change(int k,int l,int r,int p,int v){
	//if (l==1&&r==100) printf("%d %d\n",p,v);
	if (l==r){
		S[k]+=v;
		sum[k]+=v*max(0,tg[k]);
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	pushup(k);
}
void change(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		tg[k]=v;
		sum[k]=1ll*S[k]*tg[k];
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else{
		change(k*2,l,mid,x,mid,v);
		change(k*2+1,mid+1,r,mid+1,y,v);
	}
	pushup(k);
}
ll res[10];
int ans1,ans2,tp;
int main(){
	int Q,j=0,t=0;
	scanf("%d",&Q);
	For(i,1,4*Q) tg[i]=-1;
	For(i,1,Q){
		scanf("%s%d",s+i,&v[i]);
		s[i]=(s[i]-'a'+ans1)%26+'a'; v[i]^=ans2;
		if (s[i]==s[1]) change(1,1,Q,i,1);
		for (;j&&s[j+1]!=s[i];j=nxt[j])
			change(1,1,Q,i-j,-1),e[i].PB(j);
		if (i!=1&&s[j+1]==s[i]) ++j;
		for (auto d:e[j]) e[i].PB(d),change(1,1,Q,i-d,-1);
		nxt[i]=j;
		for (;t&&v[q[t]]>=v[i];--t);
		change(1,1,Q,q[t]+1,i,v[i]); q[++t]=i;
		ans1=(ans1+sum[1])%26;
		ans2=(ans2+sum[1])%(1<<30);
		res[1]+=sum[1]; tp=8;
		For(i,1,8) res[i+1]+=res[i]/10000,res[i]%=10000;
		for (;tp&&!res[tp];--tp);
		printf("%lld",res[tp]);
		Rep(j,tp-1,1) printf("%04lld",res[j]);
		puts("");
	}
}