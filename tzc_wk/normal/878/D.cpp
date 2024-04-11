#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
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
const int MAXK=12;
const int MAXS=1<<MAXK;
const int MAXN=1e5;
int n,k,qu,cnt,a[MAXK+3][MAXN+5];
bitset<MAXS+4> f[MAXN+MAXK+3];
pii ord[MAXN+5][MAXK+3];
bool cmp(pii x,pii y){return a[x.fi][x.se]>a[y.fi][y.se];}
int main(){
	scanf("%d%d%d",&n,&k,&qu);cnt=k;
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for(int j=1;j<=n;j++) for(int i=1;i<=k;i++) ord[j][i]=mp(i,j);
	for(int j=1;j<=n;j++) sort(ord[j]+1,ord[j]+k+1,cmp);
	for(int i=1;i<=k;i++) for(int j=0;j<(1<<k);j++) if(j>>i-1&1) f[i][j]=1;
	while(qu--){
		int opt,x,y;scanf("%d%d%d",&opt,&x,&y);
		if(opt==1) f[++cnt]=f[x]|f[y];
		else if(opt==2) f[++cnt]=f[x]&f[y];
		else{
			int msk=0;
			for(int i=1;i<=k;i++){
				msk|=1<<ord[y][i].fi-1;
				if(f[x][msk]){
					printf("%d\n",a[ord[y][i].fi][y]);
					break;
				}
			}
		}
	}
	return 0;
}