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
const int MAXN=2e5;
int n,m,deg[MAXN+5];u64 a,b,c;
u64 sum(u64 l,u64 r){return (l+r)*(r-l+1)/2ull;}
vector<int> g1[MAXN+5],g2[MAXN+5],g[MAXN+5];
vector<u64> s1[MAXN+5],s2[MAXN+5];
int vis[MAXN+5];
int main(){
	scanf("%d%d%llu%llu%llu",&n,&m,&a,&b,&c);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);if(u>v) u^=v^=u^=v;
		g1[v].pb(u);g2[u].pb(v);deg[u]++;deg[v]++;
	}
	u64 ans=0;
	for(int i=0;i<n;i++){
		sort(g1[i].begin(),g1[i].end());
		s1[i].resize(g1[i].size());
		for(int j=0;j<g1[i].size();j++){
			if(j==0) s1[i][j]=g1[i][j];
			else s1[i][j]=s1[i][j-1]+g1[i][j];
		}
		sort(g2[i].begin(),g2[i].end());
		s2[i].resize(g2[i].size());
		for(int j=0;j<g2[i].size();j++){
			if(j==0) s2[i][j]=g2[i][j];
			else s2[i][j]=s2[i][j-1]+g2[i][j];
		}
	}
	for(int i=0;i<n;i++){
		u64 cnt1=i-g1[i].size(),cnt2=n-i-1-g2[i].size();
		u64 sum1=sum(0,i-1)-((g1[i].empty())?0:s1[i].back());
		u64 sum2=sum(i+1,n-1)-((g2[i].empty())?0:s2[i].back());
		ans+=cnt1*cnt2*i*b+cnt1*sum2*c+cnt2*sum1*a;
	}
	for(int i=0;i<n;i++) for(int j:g2[i]){
		int pos1=lower_bound(g1[j].begin(),g1[j].end(),i)-g1[j].begin();
		int pos2=lower_bound(g2[i].begin(),g2[i].end(),j)-g2[i].begin();
		u64 cnt=g1[j].size()-1-pos1+pos2;
		u64 rem=j-i-1-cnt;
		u64 s=sum(i+1,j-1)-s1[j].back()+s1[j][pos1]-((!pos2)?0:s2[i][pos2-1]);
//		printf("%d %d %d %d\n",i,j,rem,s);
		ans-=s*b+rem*i*a+rem*j*c;
	}
	for(int i=0;i<n;i++) for(int j=0;j<g1[i].size();j++){
		int x=g1[i][j];
		if(deg[i]<deg[x]) g[i].pb(x);
		else g[x].pb(i);
	} memset(vis,-1,sizeof(vis));
	for(int i=0;i<n;i++){
		for(int j:g[i]) vis[j]=i;
		for(int j:g[i]) for(int k:g[j]){
			if(vis[k]==i){
//				printf("%d %d %d\n",i,j,k);
				u64 tmp[3]={0};tmp[0]=i;tmp[1]=j;tmp[2]=k;
				sort(tmp,tmp+3);ans-=tmp[0]*a+tmp[1]*b+tmp[2]*c;
			}
		}
	}
	printf("%llu\n",ans);
	return 0;
}