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
const int MAXN=1e5;
const int MAXLEN=2e5;
const int LOG_N=18;
int n,m=0,k,sep_id=123,len[MAXN+5],s[MAXLEN+5],bel[MAXLEN+5];char buf[MAXLEN+5];
int sa[MAXLEN+5],rk[MAXLEN+5],buc[MAXLEN+5],seq[MAXLEN+5],ht[MAXLEN+5];
pii x[MAXLEN+5];int st[MAXLEN+5][LOG_N+2];ll ans[MAXN+5];
vector<pii> mark[MAXLEN+5];
int cnt[MAXN+5],num=0,mx[MAXLEN+5];
void getsa(){
	int vmax=sep_id,gr=0;
	for(int i=1;i<=m;i++) buc[s[i]]++;
	for(int i=1;i<=vmax;i++) buc[i]+=buc[i-1];
	for(int i=m;i;i--) sa[buc[s[i]]--]=i;
	for(int i=1;i<=m;i++){
		if(s[sa[i]]!=s[sa[i-1]]) gr++;
		rk[sa[i]]=gr;
	} vmax=gr;
	for(int k=1;k<=m;k<<=1){
		for(int i=1;i<=m;i++){
			if(i+k<=m) x[i]=mp(rk[i],rk[i+k]);
			else x[i]=mp(rk[i],0);
		} memset(buc,0,sizeof(buc));gr=0;int num=0;
		for(int i=m-k+1;i<=m;i++) seq[++num]=i;
		for(int i=1;i<=m;i++) if(sa[i]>k) seq[++num]=sa[i]-k;
		for(int i=1;i<=m;i++) buc[x[i].fi]++;
		for(int i=1;i<=vmax;i++) buc[i]+=buc[i-1];
		for(int i=m;i;i--) sa[buc[x[seq[i]].fi]--]=seq[i];
		for(int i=1;i<=m;i++){
			if(x[sa[i]]!=x[sa[i-1]]) gr++;
			rk[sa[i]]=gr;
		} vmax=gr;if(vmax==m) break;
	}
}
void getht(){
	int k=0;
	for(int i=1;i<=m;i++){
		if(rk[i]==1) continue;if(k) --k;
		int j=sa[rk[i]-1];
		while(i+k<=m&&j+k<=m&&s[i+k]==s[j+k]) ++k;
		ht[rk[i]]=k;
	}
}
void buildst(){
	for(int i=1;i<=m;i++) st[i][0]=ht[i];
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=m;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
}
int getlcp(int x,int y){
	int k=31-__builtin_clz(y-x+1);
	return min(st[x][k],st[y-(1<<k)+1][k]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",buf+1);len[i]=strlen(buf+1);
		for(int j=1;j<=len[i];j++) s[++m]=buf[j],bel[m]=i;
		s[++m]=++sep_id;
	} getsa();getht();buildst();
	if(k==1){
		for(int i=1;i<=n;i++) printf("%lld%c",1ll*len[i]*(len[i]+1)/2,(i==n)?'\n':' ');
		return 0;
	}
	for(int i=1,j=1;i<=m-n;i++){
		while(j<=m-n&&num<k){
			if(!cnt[bel[sa[j]]]) num++;
			cnt[bel[sa[j]]]++;j++;
		} if(num<k) break;
//		printf("%d %d\n",i,j);
		int lcp=getlcp(i+1,j-1);
		mark[i].pb(mp(lcp,1));mark[j].pb(mp(lcp,-1));
		cnt[bel[sa[i]]]--;if(!cnt[bel[sa[i]]]) num--;
	}
	multiset<int> st;st.insert(0);
	for(int i=1;i<=m-n;i++){
		for(int j=0;j<mark[i].size();j++){
			if(mark[i][j].se==1) st.insert(mark[i][j].fi);
			else st.erase(st.find(mark[i][j].fi));
		} mx[i]=*st.rbegin();
	}
	for(int i=1;i<=m-n;i++) mx[i]=max(mx[i],min(mx[i-1],ht[i]));
	for(int i=1;i<=m-n;i++) ans[bel[sa[i]]]+=mx[i];
	for(int i=1;i<=n;i++) printf("%lld%c",ans[i],(i==n)?'\n':' ');
	return 0;
}