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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5; 
int n,m1,m2,f1[MAXN+5],f2[MAXN+5];
int find1(int x){return (!f1[x])?x:f1[x]=find1(f1[x]);}
int find2(int x){return (!f2[x])?x:f2[x]=find2(f2[x]);}
void merge1(int x,int y){x=find1(x);y=find1(y);f1[x]=y;}
void merge2(int x,int y){x=find2(x);y=find2(y);f2[x]=y;}
int main(){
	scanf("%d%d%d",&n,&m1,&m2);vector<pii> res;
	for(int i=1,u,v;i<=m1;i++) scanf("%d%d",&u,&v),merge1(u,v);
	for(int i=1,u,v;i<=m2;i++) scanf("%d%d",&u,&v),merge2(u,v);
	for(int i=2;i<=n;i++) if(find1(i)!=find1(1)&&find2(1)!=find2(i))
		res.pb(mp(1,i)),merge1(1,i),merge2(1,i);
	vector<int> v1,v2;
	for(int i=2;i<=n;i++){
		if(find1(i)!=find1(1)) v1.pb(i),merge1(1,i);
		if(find2(i)!=find2(1)) v2.pb(i),merge2(1,i);
	} for(int i=0;i<min(v1.size(),v2.size());i++)
		res.pb(mp(v1[i],v2[i]));
	printf("%d\n",res.size());
	for(pii p:res) printf("%d %d\n",p.fi,p.se);
	return 0;
}