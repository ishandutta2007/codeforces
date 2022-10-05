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
const int MAXN=1.5e5;
const double EPS=1e-9;
int n;ll T,sum[MAXN+5];
struct data{ll p,t,mn,mx;} a[MAXN+5];
bool cmp1(data lhs,data rhs){return lhs.p*rhs.t>rhs.p*lhs.t;}
bool cmp2(data lhs,data rhs){return lhs.p<rhs.p;}
bool check(double x){
	double mx=0;
	for(int i=1,j=1;i<=n;i++){
		while(a[j].p!=a[i].p) chkmax(mx,1.0*a[j].p*(1-x*a[j].mn/T)),j++;
		if(1.0*a[i].p*(1-x*a[i].mx/T)<mx) return 0;
	} return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i].p);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i].t),T+=a[i].t;
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].t;
	for(int l=1,r;l<=n;l=r+1){
		r=l;while(r<n&&a[r].p*a[r+1].t==a[r].t*a[r+1].p) r++;
		for(int i=l;i<=r;i++) a[i].mx=sum[r],a[i].mn=sum[l-1]+a[i].t;
	} sort(a+1,a+n+1,cmp2);
	double l=0,r=1.0,x=-114514.1919810;
	while(fabs(r-l)>EPS){
		double mid=(l+r)/2.0;
		if(check(mid)) x=l=mid;
		else r=mid;
	} printf("%.10lf\n",x);
	return 0;
}