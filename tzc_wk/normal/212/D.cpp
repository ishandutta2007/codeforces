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
const int MAXN=1e6;
int n,a[MAXN+5],L[MAXN+5],R[MAXN+5];stack<int> stk;
ll s0[MAXN+5],s1[MAXN+5],s[MAXN+5];
void calc(int x,int y,int v){
	if(x>y) x^=y^=x^=y;
//	printf("%d %d %d\n",x,y,v);
	s1[1]+=v;s1[x]-=v;
	s0[x]+=1ll*x*v;s0[y+1]-=1ll*x*v;
	s1[y+1]-=v;s1[y+x]+=v;
	s0[y+1]+=1ll*(x+y)*v;s0[y+x]-=1ll*(x+y)*v;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		while(!stk.empty()&&mp(a[i],i)<mp(a[stk.top()],stk.top())) stk.pop();
		L[i]=(stk.empty())?0:stk.top();stk.push(i);
	} while(!stk.empty()) stk.pop();
	for(int i=n;i;i--){
		while(!stk.empty()&&mp(a[i],i)<mp(a[stk.top()],stk.top())) stk.pop();
		R[i]=(stk.empty())?(n+1):stk.top();stk.push(i);
	}
	for(int i=1;i<=n;i++) calc(i-L[i],R[i]-i,a[i]);
	for(int i=1;i<=n;i++) s0[i]+=s0[i-1],s1[i]+=s1[i-1];
	for(int i=1;i<=n;i++) s[i]=s1[i]*i+s0[i];
	int qu;scanf("%d",&qu);
	while(qu--){int x;scanf("%d",&x);printf("%.15lf\n",1.0*s[x]/(n-x+1));}
	return 0;
}