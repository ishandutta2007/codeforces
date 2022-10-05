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
const int MAXQ=100;
const int MAXLEN=2e5+100;
const int LOG_N=19;
const int INF=0x3f3f3f3f;
int n,m,qu,sep_id=91,s[MAXLEN+5],bg[MAXQ+5],len[MAXQ+5];
char buf[MAXLEN+5];pii x[MAXLEN+5];
int sa[MAXLEN+5],rk[MAXLEN+5],buc[MAXLEN+5],seq[MAXLEN+5],ht[MAXLEN+5];
int st[MAXLEN+5][LOG_N+2],mn_id[MAXLEN+5][LOG_N+2],mx_id[MAXLEN+5][LOG_N+2];
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
	for(int i=1;i<=m;i++){
		if(sa[i]<=n) mn_id[i][0]=mx_id[i][0]=sa[i];
		else mn_id[i][0]=INF,mx_id[i][0]=0;
	}
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=m;j++){
		mn_id[j][i]=min(mn_id[j][i-1],mn_id[j+(1<<i-1)][i-1]);
		mx_id[j][i]=max(mx_id[j][i-1],mx_id[j+(1<<i-1)][i-1]);
	}
}
int getlcp(int x,int y){
	int k=31-__builtin_clz(y-x+1);
	return min(st[x][k],st[y-(1<<k)+1][k]);
}
int querymn(int x,int y){
	int k=31-__builtin_clz(y-x+1);
	return min(mn_id[x][k],mn_id[y-(1<<k)+1][k]);
}
int querymx(int x,int y){
	int k=31-__builtin_clz(y-x+1);
	return max(mx_id[x][k],mx_id[y-(1<<k)+1][k]);
}
pii get_interval(int x,int k){
	int L=1,R=x-1,l=x,r=x;
	while(L<=R){
		int mid=L+R>>1;
		if(getlcp(mid+1,x)>=k) l=mid,R=mid-1;
		else L=mid+1;
	} L=x+1,R=m;
	while(L<=R){
		int mid=L+R>>1;
		if(getlcp(x+1,mid)>=k) r=mid,L=mid+1;
		else R=mid-1;
	} return mp(l,r);
}
int main(){
	scanf("%s%d",buf+1,&qu);n=strlen(buf+1);
	for(int i=1;i<=n;i++) s[++m]=buf[i];
	for(int i=1;i<=qu;i++){
		buf[++m]=++sep_id;bg[i]=m;
		scanf("%s",buf+1);len[i]=strlen(buf+1);
		for(int j=1;j<=len[i];j++) s[++m]=buf[j];
	} getsa();getht();buildst();
	int ans=0;
	for(int i=1;i<=qu;i++){
		bool flg=0;
		for(int l=2;l<=len[i];l++){
			pii p1=get_interval(rk[bg[i]+1],l-1);
			pii p2=get_interval(rk[bg[i]+l],len[i]-l+1);
			int mn=querymn(p1.fi,p1.se);
			int mx=querymx(p2.fi,p2.se);
			if(mn==INF||mx==0) continue;
			if(mn+l-1<=mx) flg=1;
		} ans+=flg;
	} printf("%d\n",ans);
	return 0;
}