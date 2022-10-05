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
const int MAXN=1e5;
const int MAXLEN=2e5;
const int INF=0x3f3f3f3f;
const int MAX_LIM=120;
const int LOG_N=18;
int n,m,qu,len=0;
char s1[MAXN+5],s2[MAXN+5],s[MAXLEN+5];
struct query{int l,r,k,x,y;} q[MAXN+5];
int sa[MAXLEN+5],rk[MAXLEN+5],buc[MAXLEN+5],seq[MAXLEN+5],ht[MAXLEN+5];
int st_sa[MAXLEN+5][LOG_N+2];pii x[MAXLEN+5];
void getsa(){
	int vmax=122,gr=0;
	for(int i=1;i<=len;i++) buc[s[i]]++;
	for(int i=1;i<=vmax;i++) buc[i]+=buc[i-1];
	for(int i=len;i;i--) sa[buc[s[i]]--]=i;
	for(int i=1;i<=len;i++){
		if(s[sa[i]]!=s[sa[i-1]]) gr++;
		rk[sa[i]]=gr;
	} vmax=gr;
	for(int k=1;k<=len;k<<=1){
		for(int i=1;i<=len;i++){
			if(i+k<=len) x[i]=mp(rk[i],rk[i+k]);
			else x[i]=mp(rk[i],0);
		} memset(buc,0,sizeof(buc));gr=0;int num=0;
		for(int i=len-k+1;i<=len;i++) seq[++num]=i;
		for(int i=1;i<=len;i++) if(sa[i]>k) seq[++num]=sa[i]-k;
		for(int i=1;i<=len;i++) buc[x[i].fi]++;
		for(int i=1;i<=vmax;i++) buc[i]+=buc[i-1];
		for(int i=len;i;i--) sa[buc[x[seq[i]].fi]--]=seq[i];
		for(int i=1;i<=len;i++){
			if(x[sa[i]]!=x[sa[i-1]]) gr++;
			rk[sa[i]]=gr;
		} vmax=gr;if(vmax==len) break;
	}
}
void getht(){
	int k=0;
	for(int i=1;i<=len;i++){
		if(rk[i]==1) continue;if(k) --k;
		int j=sa[rk[i]-1];
		while(i+k<=len&&j+k<=len&&s[i+k]==s[j+k]) ++k;
		ht[rk[i]]=k;
	}
}
void buildst(){
	for(int i=1;i<=len;i++) st_sa[i][0]=ht[i];
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=len;j++)
		st_sa[j][i]=min(st_sa[j][i-1],st_sa[j+(1<<i-1)][i-1]);
}
int get_sa_mn(int x,int y){
	int k=31-__builtin_clz(y-x+1);
	return min(st_sa[x][k],st_sa[y-(1<<k)+1][k]);
}
int getlcp(int x,int y){
	x=rk[x];y=rk[y];if(x>y) swap(x,y);
	return get_sa_mn(x+1,y);
}
int getcmp(int x,int y,int k){
	if(getlcp(x,y)>=k) return 0;
	return (rk[x]<rk[y])?1:-1;
}
bool getst(int x,int y){
	int swp=0;if(x>y) swap(x,y),swp=1;
	if(x+m<y){
		int st=getcmp(n+2,x+1,m);if(st!=0) return (st>0)^swp;
		st=getcmp(x+1,x+m+1,y-(x+m));if(st!=0) return (st>0)^swp;
		st=getcmp(y+1-m,n+2,m);if(st!=0) return (st>0)^swp;
		return swp^1;
	} else {
		int st=getcmp(n+2,x+1,y-x);if(st!=0) return (st>0)^swp;
		st=getcmp(n+2+y-x,n+2,m-(y-x));if(st!=0) return (st>0)^swp;
		st=getcmp(x+1,n+2+m-(y-x),y-x);if(st!=0) return (st>0)^swp;
		return swp^1;
	}
}
int ord[MAXN+5],rk_pos[MAXN+5];
int pos_mn[MAXN+5][LOG_N+5];
void buildst_pos(){
	for(int i=0;i<=n;i++) pos_mn[i][0]=rk_pos[i];
	for(int i=1;i<=LOG_N;i++) for(int j=0;j+(1<<i)-1<=n;j++)
		pos_mn[j][i]=min(pos_mn[j][i-1],pos_mn[j+(1<<i-1)][i-1]);
}
int get_pos_mn(int l,int r){
	if(l>r) return INF;int k=31-__builtin_clz(r-l+1);
	return min(pos_mn[l][k],pos_mn[r-(1<<k)+1][k]);
}
int ans[MAXN+5],lim;
void solve_big(){
	buildst_pos();
	for(int i=1;i<=qu;i++) if(q[i].k>lim){
		for(int j=0;j*q[i].k<=n+q[i].k;j++){
			chkmin(ans[i],get_pos_mn(max(q[i].l,j*q[i].k+q[i].x),min(q[i].r,j*q[i].k+q[i].y)));
		}
	}
}
int pos_mn2[MAXN+5][LOG_N+5];
int get_pos_mn2(int l,int r){
	if(l>r) return INF;int k=31-__builtin_clz(r-l+1);
	return min(pos_mn2[l][k],pos_mn2[r-(1<<k)+1][k]);
}
vector<int> qv[MAX_LIM+2];
void solve_small(){
	for(int i=1;i<=qu;i++) if(q[i].k<=lim) qv[q[i].k].pb(i);
	for(int i=1;i<=lim;i++){
		for(int j=0;j<i;j++){
			int k=0;
			for(int t=j;t<=n;k++,t+=i) pos_mn2[k][0]=rk_pos[t];
			for(int t=1;t<=LOG_N;t++) for(int l=0;l+(1<<t)-1<=k;l++)
				pos_mn2[l][t]=min(pos_mn2[l][t-1],pos_mn2[l+(1<<t-1)][t-1]);
			for(int t=0;t<qv[i].size();t++){
				int id=qv[i][t];
				if(q[id].x<=j&&j<=q[id].y){
					int tl=(q[id].l%q[id].k<=j)?(q[id].l/q[id].k):(q[id].l/q[id].k+1);
					int tr=(q[id].r%q[id].k<j)?(q[id].r/q[id].k-1):(q[id].r/q[id].k);
//					printf("%d %d %d %d %d %d\n",j,q[id].k,q[id].l,q[id].r,tl,tr);
					chkmin(ans[id],get_pos_mn2(tl,tr));
				}
			}
		}
	}
}
int main(){
	scanf("%s%s%d",s1+1,s2+1,&qu);n=strlen(s1+1);m=strlen(s2+1);
	for(int i=1;i<=n;i++) s[++len]=s1[i];s[++len]='#';
	for(int i=1;i<=m;i++) s[++len]=s2[i];getsa();getht();buildst();
//	printf("%s\n",s+1);
//	for(int i=1;i<=len;i++) printf("%d %d %d\n",sa[i],rk[i],ht[i]);
	for(int i=1;i<=n+1;i++) ord[i]=i-1;sort(ord+1,ord+n+2,getst);
	for(int i=1;i<=n+1;i++) rk_pos[ord[i]]=i;
//	for(int i=1;i<=n+1;i++) printf("%d\n",ord[i]);
	for(int i=1;i<=qu;i++) scanf("%d%d%d%d%d",&q[i].l,&q[i].r,&q[i].k,&q[i].x,&q[i].y);
	memset(ans,63,sizeof(ans));lim=100;
	solve_big();solve_small();
	for(int i=1;i<=qu;i++) printf("%d ",(ans[i]==INF)?-1:ord[ans[i]]);
	return 0;
}
/*
abc d 4
0 3 2 0 0
0 3 1 0 0
1 2 1 0 0
0 1 3 2 2
*/