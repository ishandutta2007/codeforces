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
const int MAXN=5e5;
const int LOG_N=19;
int n;char s[MAXN+5];pii x[MAXN+5];
int sa[MAXN+5],rk[MAXN+5],buc[MAXN+5],seq[MAXN+5],ht[MAXN+5];
int sum[MAXN+5];vector<int> pos[MAXN*2+5];
void getsa(){
	int t_t=0,vmax=2,gr=0;
	for(int i=1;i<=n;i++) if(s[i]=='(') sa[++t_t]=i,rk[i]=1;
	for(int i=1;i<=n;i++) if(s[i]==')') sa[++t_t]=i,rk[i]=2;
	for(int k=1;k<=n;k<<=1){
		for(int i=1;i<=n;i++){
			if(i+k<=n) x[i]=mp(rk[i],rk[i+k]);
			else x[i]=mp(rk[i],0);
		} memset(buc,0,sizeof(buc));gr=0;int num=0;
		for(int i=n-k+1;i<=n;i++) seq[++num]=i;
		for(int i=1;i<=n;i++) if(sa[i]>k) seq[++num]=sa[i]-k;
		for(int i=1;i<=n;i++) buc[x[i].fi]++;
		for(int i=1;i<=vmax;i++) buc[i]+=buc[i-1];
		for(int i=n;i;i--) sa[buc[x[seq[i]].fi]--]=seq[i];
		for(int i=1;i<=n;i++){
			if(x[sa[i]]!=x[sa[i-1]]) gr++;
			rk[sa[i]]=gr;
		} vmax=gr;if(vmax==n) break;
	}
}
void getht(){
	int k=0;
	for(int i=1;i<=n;i++){
		if(rk[i]==1) continue;if(k) --k;
		int j=sa[rk[i]-1];
		while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) ++k;
		ht[rk[i]]=k;
	}
}
int mn[MAXN+5][LOG_N+2];
int getmn(int l,int r){
	int k=31-__builtin_clz(r-l+1);
	return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int getpos(int x,int l,int r){
	int pl=lower_bound(pos[x].begin(),pos[x].end(),l)-pos[x].begin();
	int pr=upper_bound(pos[x].begin(),pos[x].end(),r)-pos[x].begin();
	return pr-pl;
}
int main(){
	scanf("%d%s",&n,s+1);getsa();getht();
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+((s[i]^')')?1:-1);
	for(int i=1;i<=n;i++) pos[sum[i]+n].pb(i);
	for(int i=1;i<=n;i++) mn[i][0]=sum[i];
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n;j++)
		mn[j][i]=min(mn[j][i-1],mn[j+(1<<i-1)][i-1]);
	ll ans=0;
	for(int i=1;i<=n;i++){
		int lwb=sa[i]+ht[i];
		int L=sa[i],R=n,upb=sa[i]-1;
		while(L<=R){
			int mid=L+R>>1;
			if(getmn(sa[i],mid)>=sum[sa[i]-1]) upb=mid,L=mid+1;
			else R=mid-1;
		} if(upb>=lwb) ans+=getpos(sum[sa[i]-1]+n,lwb,upb);
//		printf("%d %d %d\n",sa[i],lwb,upb);
	} printf("%lld\n",ans);
	return 0;
}