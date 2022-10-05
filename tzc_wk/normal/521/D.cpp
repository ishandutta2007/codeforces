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
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
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
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
int n,m,k,ini[MAXN+5],c1,c2,c3;
struct event{int opt,id,x;ll a,b;} q1[MAXN+5],q2[MAXN+5],q3[MAXN+5];
bool cmp1(event lhs,event rhs){return (lhs.x^rhs.x)?(lhs.x<rhs.x):(lhs.a<rhs.a);}
bool cmp2(event lhs,event rhs){return (lhs.x^rhs.x)?(lhs.x<rhs.x):(lhs.a>rhs.a);}
bool cmp3(event lhs,event rhs){return lhs.a*rhs.b>rhs.a*lhs.b;}
bool cmp4(event lhs,event rhs){return lhs.opt<rhs.opt;}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",&ini[i]);
	for(int i=1;i<=m;i++){
		int opt,x,y;scanf("%d%d%d",&opt,&x,&y);
		if(opt==1&&y>ini[x]) q1[++c1]={1,i,x,y,1};
		else if(opt==2) q2[++c2]={2,i,x,y,1};
		else if(opt==3) q3[++c3]={3,i,x,y,1};
	} sort(q1+1,q1+c1+1,cmp1);
	for(int i=1;i<=c1;i++) if(q1[i].x!=q1[i+1].x)
		q2[++c2]={q1[i].opt,q1[i].id,q1[i].x,q1[i].a-ini[q1[i].x],1};
	sort(q2+1,q2+c2+1,cmp2);ll sum=0;
	for(int i=1;i<=c2;i++){
		if(q2[i].x!=q2[i-1].x) sum=ini[q2[i].x];
		q3[++c3]={q2[i].opt,q2[i].id,q2[i].x,sum+q2[i].a,sum};sum+=q2[i].a;
//		printf("%d %d %d %lld\n",q2[i].opt,q2[i].id,q2[i].x,q2[i].a);
	} for(int i=1;i<=c3;i++) q3[i].a-=q3[i].b;
	sort(q3+1,q3+c3+1,cmp3);k=min(c3,k);
	sort(q3+1,q3+k+1,cmp4);printf("%d\n",k);
	for(int i=1;i<=k;i++) printf("%d ",q3[i].id);
	return 0;
}