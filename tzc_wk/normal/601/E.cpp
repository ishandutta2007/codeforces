#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int BASE=1e7+19;
const int MOD=1e9+7;
const int MAXN=15000;
const int MAXQ=3e4;
const int MAXK=1e3;
int pwb[MAXK+5];
int n,m,p,qu,v[MAXN+5],w[MAXN+5],pre[MAXN+5];
bool in[MAXN+5],isq[MAXQ+5];
int ans=0,dp[MAXK+5];
struct node{int l,r;vector<int> v;} s[MAXQ*4+5];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void add(int k,int l,int r,int x){
	if(l<=s[k].l&&s[k].r<=r){s[k].v.pb(x);return;}
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) add(k<<1,l,r,x);
	else if(l>mid) add(k<<1|1,l,r,x);
	else add(k<<1,l,mid,x),add(k<<1|1,mid+1,r,x);
}
void iterate(int k){
	int tmp[MAXK+5]={0};
	memcpy(tmp,dp,sizeof(dp));
	for(int i=0;i<s[k].v.size();i++){
		int id=s[k].v[i];
		for(int j=p;j>=w[id];j--)
			dp[j]=max(dp[j],dp[j-w[id]]+v[id]);
	}
	if(s[k].l==s[k].r){
//		printf("Time %d: ",s[k].l);
//		for(int j=1;j<=p;j++) printf("%d%c",dp[j],(j==p)?'\n':' ');
		int ans=0,mx=0;
		for(int j=1;j<=p;j++){chkmax(mx,dp[j]);ans=(ans+1ll*mx*pwb[j-1]%MOD)%MOD;}
		if(isq[s[k].l]) printf("%d\n",ans);
	}
	else iterate(k<<1),iterate(k<<1|1);
	memcpy(dp,tmp,sizeof(tmp));
}
int main(){
	scanf("%d%d",&n,&p);m=n;
	pwb[0]=1;for(int i=1;i<=p;i++) pwb[i]=1ll*pwb[i-1]*BASE%MOD;
	for(int i=1;i<=n;i++) scanf("%d%d",&v[i],&w[i]),in[i]=1;
	scanf("%d",&qu);build(1,0,qu);
	for(int i=1;i<=qu;i++){
		int opt;scanf("%d",&opt);
		if(opt==1) m++,scanf("%d%d",&v[m],&w[m]),in[m]=1,pre[m]=i;
		else if(opt==2){int x;scanf("%d",&x);add(1,pre[x],i-1,x);in[x]=0;}
		else isq[i]=1;
	}
	for(int i=1;i<=m;i++) if(in[i]) add(1,pre[i],qu,i);
	iterate(1);
	return 0;
}