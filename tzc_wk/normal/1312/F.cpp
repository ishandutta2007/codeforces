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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=3e5;
int n,x,y,z,per,vis[6],sg[55][4];ll a[MAXN+5];
int calc(ll x,int y){
	if(x<=0) return 0;
	if(x<=30) return sg[x][y];
	return sg[x%per+30/per*per][y];
}
void solve(){
	scanf("%d%d%d%d",&n,&x,&y,&z);
	memset(sg,0,sizeof(sg));
	for(int i=1;i<=50;i++){
		for(int j=1;j<=3;j++){
			memset(vis,0,sizeof(vis));
			vis[sg[max(i-x,0)][1]]=1;
			if(j^2) vis[sg[max(i-y,0)][2]]=1; 
			if(j^3) vis[sg[max(i-z,0)][3]]=1; 
			while(vis[sg[i][j]]) ++sg[i][j];
//			printf("%d%c",sg[i][j]," \n"[j==3]);
		}
	} per=-1;
	for(int i=1;i<=15;i++){
		bool flg=1;int cur=0;
		while(cur<=30) cur+=i;
		for(int j=30;j<=50;j++) for(int k=1;k<=3;k++)
			flg&=(sg[j][k]==sg[j%i+cur][k]);
		if(flg){per=i;break;}
	} assert(~per);int res=0;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) res^=calc(a[i],1);
	if(!res) puts("0");
	else{
		int ans=0;
		for(int i=1;i<=n;i++){
			int rst=res^calc(a[i],1);
			if(rst==calc(max(a[i]-x,0ll),1)) ans++;
			if(rst==calc(max(a[i]-y,0ll),2)) ans++;
			if(rst==calc(max(a[i]-z,0ll),3)) ans++;
		} printf("%d\n",ans);
	}
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}