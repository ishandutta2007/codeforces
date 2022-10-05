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
const int MAXN=2e5;
const int INF=1061109567;
int n,a[MAXN+5],b[MAXN+5],f[MAXN+5],c[MAXN+5],suf[MAXN+5],res=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]<=n&&b[i]<=n) return puts("-1"),0;
		f[min(a[i],b[i])]=max(a[i],b[i]);
		c[min(a[i],b[i])]=(a[i]>b[i]);
	} stack<int> s1,s2;s1.push(INF);s2.push(INF);
	for(int i=n;i;i--) suf[i]=max(suf[i+1],f[i]);
//	for(int i=1;i<=n;i++) printf("%d%c",f[i]," \n"[i==n]);
//	for(int i=1;i<=n;i++) printf("%d%c",c[i]," \n"[i==n]);
	int c1=0,c2=0,mn=INF;
	for(int i=1;i<=n;i++){
		if(f[i]<s1.top()) s1.push(f[i]),c1+=c[i];
		else if(f[i]<s2.top()) s2.push(f[i]),c2+=c[i];
		else return puts("-1"),0;
		if(s1.top()>s2.top()) swap(s1,s2),swap(c1,c2);
		chkmin(mn,f[i]);
		if(mn>suf[i+1]){
			res+=min(s1.size()-1-c1+c2,s2.size()-1-c2+c1);
			while(!s1.empty()) s1.pop();
			while(!s2.empty()) s2.pop();
			s1.push(INF);s2.push(INF);c1=c2=0;
		}
	} printf("%d\n",res);
	return 0;
}