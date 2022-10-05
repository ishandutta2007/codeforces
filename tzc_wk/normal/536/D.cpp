#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
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
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e3;
const int MAXM=1e5;
int n,m,s,t,p[MAXN+5],to[MAXM*2+5],nxt[MAXM*2+5],cst[MAXM*2+5],hd[MAXN+5],ec=0;
void adde(int u,int v,int w){to[++ec]=v;cst[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
ll d1[MAXN+5],d2[MAXN+5],key1[MAXN+5],key2[MAXN+5],uni1[MAXN+5],uni2[MAXN+5];
int c1[MAXN+5],c2[MAXN+5],num1=0,num2=0,cnt[MAXN+5][MAXN+5];ll sum[MAXN+5][MAXN+5];
ll dp[2][MAXN+5][MAXN+5],mn[2][MAXN+5][MAXN+5];
int nt1[MAXN+5][MAXN+5],nt2[MAXN+5][MAXN+5];
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1,u,v,w;i<=m;i++){scanf("%d%d%d",&u,&v,&w);adde(u,v,w);adde(v,u,w);}
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	memset(d1,63,sizeof(d1));d1[s]=0;q.push(mp(0,s));
	while(!q.empty()){
		pii pr=q.top();q.pop();int x=pr.se;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cst[e];
			if(d1[y]>d1[x]+z){
				d1[y]=d1[x]+z;
				q.push(mp(d1[y],y));
			}
		}
	}
	memset(d2,63,sizeof(d2));d2[t]=0;q.push(mp(0,t));
	while(!q.empty()){
		pii pr=q.top();q.pop();int x=pr.se;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cst[e];
			if(d2[y]>d2[x]+z){
				d2[y]=d2[x]+z;
				q.push(mp(d2[y],y));
			}
		}
	}
	for(int i=1;i<=n;i++) key1[i]=d1[i],key2[i]=d2[i];
	sort(key1+1,key1+n+1);sort(key2+1,key2+n+1);key1[0]=key2[0]=-1;
	for(int i=1;i<=n;i++){
		if(key1[i]!=key1[i-1]) uni1[++num1]=key1[i];
		if(key2[i]!=key2[i-1]) uni2[++num2]=key2[i];
	}
	for(int i=1;i<=n;i++) c1[i]=lower_bound(uni1+1,uni1+num1+1,d1[i])-uni1;
	for(int i=1;i<=n;i++) c2[i]=lower_bound(uni2+1,uni2+num2+1,d2[i])-uni2;
//	for(int i=1;i<=n;i++) printf("%d %d\n",c1[i],c2[i]);
	for(int i=1;i<=n;i++) cnt[c1[i]][c2[i]]++,sum[c1[i]][c2[i]]+=p[i];
	for(int i=num1;i;i--) for(int j=num2;j;j--){
		cnt[i][j]+=cnt[i+1][j]+cnt[i][j+1]-cnt[i+1][j+1];
		sum[i][j]+=sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1];
	}
//	for(int i=1;i<=num1;i++) for(int j=1;j<=num2;j++)
//		printf("%d %d %lld %lld\n",i,j,cnt[i][j],sum[i][j]);
	for(int i=num1;i;i--) for(int j=num2;j;j--){
		nt1[i][j]=(cnt[i][j]==cnt[i+1][j])?nt1[i+1][j]:(i+1);
		nt2[i][j]=(cnt[i][j]==cnt[i][j+1])?nt2[i][j+1]:(j+1);
	}
	for(int i=num1;i;i--) for(int j=num2;j;j--){
		if(!cnt[i][j]) continue;
		dp[0][i][j]=sum[i][j]-mn[1][nt1[i][j]][j];
		dp[1][i][j]=sum[i][j]-mn[0][i][nt2[i][j]];
//		printf("%d %d %d %d\n",i,j,dp[0][i][j],dp[1][i][j]);
		mn[0][i][j]=min(mn[0][i][j+1],dp[0][i][j]);
		mn[1][i][j]=min(mn[1][i+1][j],dp[1][i][j]);
	} ll sgn=sum[1][1]-(dp[0][1][1]<<1);
//	printf("%d\n",dp[0][1][1]);
	printf("%s\n",(sgn>0)?"Cry":((!sgn)?"Flowers":"Break a heart"));
	return 0;
}