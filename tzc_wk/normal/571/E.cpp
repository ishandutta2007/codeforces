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
typedef unsigned int u32;
typedef unsigned long long u64;
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
const int MAXN=100;
const int MAXP=1200;
const int MOD=1e9+7;
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1;y=0;return;} exgcd(b,a%b,y,x);y-=(a/b)*x;
}
int qpow(int x,ll e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,m,a[MAXN+5],b[MAXN+5],p[MAXP+5];
bool vis[MAXN+5];
void getpri(int x){
	for(int i=2;i*i<=x;i++) if(x%i==0){
		p[++m]=i;while(x%i==0) x/=i;
	} if(x>1) p[++m]=x;
}
int ap[MAXN+5][MAXP+5],bp[MAXN+5][MAXP+5],ans=1;
ll ans1[MAXP+5],ans2[MAXN+5];
void calc(int x){
	int tmpa=a[x],tmpb=b[x];
	for(int i=1;i<=m;i++){
		while(tmpa%p[i]==0) tmpa/=p[i],ap[x][i]++;
		while(tmpb%p[i]==0) tmpb/=p[i],bp[x][i]++;
	}
}
void solve(int a1,int b1,int c1,int a2,int b2,int c2){
//	debug(20060729);
//	printf("%dx+%dy=%d\n%dx+%dy=%d\n",a1,b1,c1,a2,b2,c2);
	int lcm=a1/__gcd(a1,a2)*a2;
	int mul1=lcm/a1,mul2=lcm/a2;
	b1*=mul1;c1*=mul1;b2*=mul2;c2*=mul2;
	if((c1-c2)%(b1-b2)) puts("-1"),exit(0);
	int x,y;y=(c1-c2)/(b1-b2);
	b1/=mul1;c1/=mul1;b2/=mul2;c2/=mul2;
	int rem=c1-b1*y;if(rem%a1) puts("-1"),exit(0);
	x=rem/a1;if(x<0||y<0) puts("-1"),exit(0);
//	printf("%d %d\n",x,y);
	for(int i=1;i<=m;i++) ans1[i]=ap[1][i]+x*bp[1][i];
//	for(int i=1;i<=m;i++) printf("%d^%lld\n",p[i],ans1[i]);
	memset(ans2,-1,sizeof(ans2));
	for(int j=1;j<=n;j++){
		for(int k=1;k<=m;k++){
			if(vis[k]) continue;
			if(!bp[j][k]){
				if(ap[j][k]!=ans1[k]) return puts("-1"),void();
			} else {
				if(ap[j][k]>ans1[k]||(ans1[k]-ap[j][k])%bp[j][k]) return puts("-1"),void();
				else if(~ans2[j]&&(ans1[k]-ap[j][k])/bp[j][k]!=ans2[j]) return puts("-1"),void();
				else ans2[j]=(ans1[k]-ap[j][k])/bp[j][k];
			}
		}
	}
	for(int j=1;j<=m;j++) if(!vis[j])
		ans=1ll*ans*qpow(p[j],ans1[j])%MOD;
	printf("%d\n",ans);
}
bool combine(ll &a1,ll &m1,ll a2,ll m2){
//	printf("%lld %lld %lld %lld\n",a1,m1,a2,m2);
	ll k1,k2,g=__gcd(m1,m2);exgcd(m1,m2,k1,k2);
	if((a2-a1)%g) return 0;ll t=((a2-a1)/g*k1%m2+m2)%m2;
	return a1+=t*m1%(m1/g*m2),m1*=m2/g,a1=(a1%m1+m1)%m1,1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++) getpri(a[i]),getpri(b[i]);
	sort(p+1,p+m+1);m=unique(p+1,p+m+1)-p-1;
	for(int i=1;i<=n;i++) calc(i);
	for(int i=1;i<=m;i++){
		int pos0=0,pos1=0;
		for(int j=1;j<=n;j++){
			if(!bp[j][i]) pos0=j;
			else pos1=j;
		}
		if(pos0){
//			printf("%d\n",i);
			if(!pos1){
				for(int j=1;j<=n;j++) if(ap[j][i]!=ap[1][i])
					return puts("-1"),0;
				ans=1ll*ans*qpow(p[i],ap[1][i])%MOD;vis[i]=1;
			} else {
				if(ap[pos0][i]<ap[pos1][i]) return puts("-1"),0;
				if((ap[pos0][i]-ap[pos1][i])%bp[pos1][i]) return puts("-1"),0;
				int cc=(ap[pos0][i]-ap[pos1][i])/bp[pos1][i];
//				printf("%d %d %d\n",pos0,pos1,cc);
				for(int j=1;j<=m;j++) ans1[j]=1ll*bp[pos1][j]*cc+ap[pos1][j];
				memset(ans2,-1,sizeof(ans2));
				for(int j=1;j<=n;j++){
					for(int k=1;k<=m;k++){
						if(vis[k]) continue;
						if(!bp[j][k]){
							if(ap[j][k]!=ans1[k]) return puts("-1"),0;
						} else {
							if(ap[j][k]>ans1[k]||(ans1[k]-ap[j][k])%bp[j][k]) return puts("-1"),0;
							else if(~ans2[j]&&(ans1[k]-ap[j][k])/bp[j][k]!=ans2[j]) return puts("-1"),0;
							else ans2[j]=(ans1[k]-ap[j][k])/bp[j][k];
						}
					}
				}
				for(int j=1;j<=m;j++) if(!vis[j])
					ans=1ll*ans*qpow(p[j],ans1[j])%MOD;
				printf("%d\n",ans);return 0;
			}
		}
	} int pos=1;while(vis[pos]) pos++;
	if(pos==m+1) return printf("%d\n",ans),0;
	for(int i=1;i<=n;i++) swap(ap[i][pos],ap[i][1]),swap(bp[i][pos],bp[i][1]);
	swap(vis[pos],vis[1]);swap(p[pos],p[1]);debug(1);
//	printf("%d\n",pos);
	for(int j=2;j<=m;j++) if(!vis[j]){
		for(int i=2;i<=n;i++){
			if(bp[1][1]*bp[i][j]!=bp[1][j]*bp[i][1]){
				solve(bp[1][1],-bp[i][1],ap[i][1]-ap[1][1],
				bp[1][j],-bp[i][j],ap[i][j]-ap[1][j]);
				return 0;
			}
		}
	} //debug(20060617);
	ll A=ap[1][1]%bp[1][1],M=bp[1][1],mx=ap[1][1];
//	debug(114514);
	for(int i=2;i<=n;i++){
		if(!combine(A,M,ap[i][1]%bp[i][1],bp[i][1]))
			return puts("-1"),0;
		chkmax(mx,ap[i][1]);
	} //debug(20210406);
	if(A<mx) A+=(mx-A+M-1)/M*M;
	ll cc=(A-ap[1][1])/bp[1][1];
	for(int i=1;i<=m;i++) ans1[i]=ap[1][i]+cc*bp[1][i];
//	for(int i=1;i<=m;i++) printf("%d^%lld\n",p[i],ans1[i]);
	memset(ans2,-1,sizeof(ans2));
	for(int j=1;j<=n;j++){
		for(int k=1;k<=m;k++){
			if(vis[k]) continue;
			if(!bp[j][k]){
				if(ap[j][k]!=ans1[k]) return puts("-1"),0;
			} else {
				if(ap[j][k]>ans1[k]||(ans1[k]-ap[j][k])%bp[j][k]) return puts("-1"),0;
				else if(~ans2[j]&&(ans1[k]-ap[j][k])/bp[j][k]!=ans2[j]) return puts("-1"),0;
				else ans2[j]=(ans1[k]-ap[j][k])/bp[j][k];
			}
		}
	}
	for(int j=1;j<=m;j++) if(!vis[j])
		ans=1ll*ans*qpow(p[j],ans1[j])%MOD;
	printf("%d\n",ans);
	return 0;
}