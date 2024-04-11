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
const int MAXN=2e5;
int n,a[MAXN+5],b[MAXN+5],ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	vector<int> v1,v2;
	for(int i=1;i<=n;i++){
		if(a[i]<b[i]) v1.pb(i);
		if(a[i]>b[i]) v2.pb(i);
	}
	sort(v1.begin(),v1.end(),[](int x,int y){return a[x]<a[y];});
	sort(v2.begin(),v2.end(),[](int x,int y){return b[x]<b[y];});
	for(int i=0,j=0,mx=0;i<v1.size();i++){
		while(j<v2.size()&&b[v2[j]]<=a[v1[i]]){
			chkmax(mx,a[v2[j]]);j++;
		} chkmax(ans,min(mx-a[v1[i]],b[v1[i]]-a[v1[i]]));
	}
	for(int i=0,j=0,mx=0;i<v2.size();i++){
		while(j<v1.size()&&a[v1[j]]<=b[v2[i]]){
			chkmax(mx,b[v1[j]]);j++;
		} chkmax(ans,min(mx-b[v2[i]],a[v2[i]]-b[v2[i]]));
	} ll sum=0;
	for(int i=1;i<=n;i++) sum+=abs(a[i]-b[i]);
	printf("%lld\n",sum-(ans<<1));
	return 0;
}