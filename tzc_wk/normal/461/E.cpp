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
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int MAXP=2e5;
const int INF=0x3f3f3f3f;
const ll INFll=0x3f3f3f3f3f3f3f3fll;
ll n;int len;char str[MAXN+5];
struct node{int ch[5],len,lnk;} s[MAXP+5];
int ncnt=1,cur=1;
void extend(char c){
	int id=c-'A',nw=++ncnt,p=cur;
	s[nw].len=s[cur].len+1;cur=nw;
	while(p&&!s[p].ch[id]) s[p].ch[id]=nw,p=s[p].lnk;
	if(!p) return s[nw].lnk=1,void();
	int q=s[p].ch[id];
	if(s[q].len==s[p].len+1) return s[nw].lnk=q,void();
	int cl=++ncnt;s[cl].lnk=s[q].lnk;s[q].lnk=s[nw].lnk=cl;
	for(int i=0;i<4;i++) s[cl].ch[i]=s[q].ch[i];
	while(p&&s[p].ch[id]==q) s[p].ch[id]=cl,p=s[p].lnk;
}
int dp[MAXP+5][4];
int calc(int x,int c){
	if(~dp[x][c]) return dp[x][c];
	if(!s[x].ch[c]) return 0;dp[x][c]=INF;
	for(int i=0;i<4;i++) if(s[x].ch[i]) chkmin(dp[x][c],calc(s[x].ch[i],c)+1);
	return dp[x][c];
}
struct mat{
	ll a[4][4];
	mat(){memset(a,63,sizeof(a));}
	mat operator *(const mat &rhs){
		mat res;
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) for(int k=0;k<4;k++)
			chkmin(res.a[i][j],a[i][k]+rhs.a[k][j]);
		return res;
	}
} trs;
bool check(ll mid){
	mat res,tmp=trs;for(int i=0;i<4;i++) res.a[i][i]=0;ll mn=INFll;
//	printf("%lld:\n",mid);
	for(;mid;mid>>=1,tmp=tmp*tmp) if(mid&1) res=res*tmp;
	for(int i=0;i<4;i++) for(int j=0;j<4;j++) chkmin(mn,res.a[i][j]);
//	for(int i=0;i<4;i++) for(int j=0;j<4;j++) printf("%lld%c",res.a[i][j]," \n"[j==3]);
	return (mn>=n);
}
int main(){
	scanf("%lld%s",&n,str+1);len=strlen(str+1);
	for(int i=1;i<=len;i++) extend(str[i]);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<4;i++) for(int j=0;j<4;j++){
		trs.a[i][j]=calc(s[1].ch[i],j)+1;
//		printf("%lld%c",trs.a[i][j]," \n"[j==3]);
	}
	ll l=1,r=n,p=0;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid)) p=mid,r=mid-1;
		else l=mid+1;
	} printf("%lld\n",p);
	return 0;
}