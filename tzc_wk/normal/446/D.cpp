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
const int MAXN=500;
const int MAXM=101;
const int TOT=601;
int n,m,k,deg[MAXN+5],num[MAXN+5][MAXN+5];
bool is[MAXN+5];int rm[MAXN+5],id[MAXN+5],cnt=0;
double a[MAXN+5][TOT+5],f[MAXN+5][MAXM+5];
struct mat{
	double a[MAXM+5][MAXM+5];
	mat(){for(int i=1;i<=MAXM;i++) for(int j=1;j<=MAXM;j++) a[i][j]=0;}
	mat operator *(const mat &rhs){
		mat ret;
		for(int i=1;i<=cnt;i++) for(int j=1;j<=cnt;j++)
			for(int l=1;l<=cnt;l++) ret.a[i][j]+=a[i][l]*rhs.a[l][j];
		return ret;
	}
};
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&is[i]);
		if(is[i]) rm[++cnt]=i,id[i]=cnt;
	}
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);deg[u]++;deg[v]++;
		num[u][v]++;num[v][u]++;
	}
//	for(int i=1;i<=n;i++) printf("%d\n",deg[i]);
	for(int i=1;i<=n;i++){
		if(!is[i]){
			a[i][i]=-1;
			for(int j=1;j<=n;j++) if(i^j)
				a[i][j]=1.0*num[i][j]/deg[i];
		} else {
			a[i][i]=a[i][id[i]+n]=1;
		}
	}
//	for(int i=1;i<=n;i++) for(int j=1;j<=n+cnt;j++)
//		printf("%.10lf%c",a[i][j],(j==n+cnt)?'\n':' ');
	for(int i=1;i<=n;i++){
		int pos=i;
		for(int j=i+1;j<=n;j++) if(fabs(a[j][i])>fabs(a[pos][i])) pos=j;
		for(int j=i;j<=n+cnt;j++) swap(a[pos][j],a[i][j]);
		for(int j=i+1;j<=n+cnt;j++) a[i][j]/=a[i][i];a[i][i]=1;
		for(int j=i+1;j<=n;j++){
			for(int k=i+1;k<=n+cnt;k++) a[j][k]-=a[i][k]*a[j][i];
			a[j][i]=0;
		}
	}
	for(int i=1;i<=cnt;i++) for(int j=n;j;j--){
		f[j][i]=a[j][i+n];
		for(int k=j+1;k<=n;k++) f[j][i]-=a[j][k]*f[k][i];
//		printf("%d %d %.10lf\n",j,i,f[j][i]);
	} mat trs,ini,mul;
	for(int i=1;i<=cnt;i++) for(int j=1;j<=cnt;j++){
		for(int l=1;l<=n;l++) trs.a[j][i]+=1.0*num[rm[i]][l]/deg[rm[i]]*f[l][j];
//		printf("%d %d %.10lf\n",i,j,trs.a[i][j]);
	}
	for(int i=1;i<=cnt;i++) ini.a[i][1]=f[1][i];
	k-=2;for(int i=1;i<=cnt;i++) mul.a[i][i]=1;
	for(;k;k>>=1,trs=trs*trs) if(k&1) mul=mul*trs;
	ini=mul*ini;printf("%.10lf\n",ini.a[cnt][1]);
	return 0;
}