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
const int MAXN=1e3; 
int n,x[MAXN+5],y[MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	while(1){
		static int cnt[2][2];memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++) cnt[x[i]&1][y[i]&1]++;
		if(cnt[0][0]+cnt[1][1]>0&&cnt[0][1]+cnt[1][0]>0){
			vector<int> ans;
			for(int i=1;i<=n;i++) if((x[i]&1)^(y[i]&1)) ans.pb(i);
			printf("%d\n",ans.size());
			for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
			printf("\n");return 0;
		} else if(cnt[0][0]>0&&cnt[1][1]>0||cnt[0][1]>0&&cnt[1][0]>0){
			vector<int> ans;
			for(int i=1;i<=n;i++) if(x[i]&1) ans.pb(i);
			printf("%d\n",ans.size());
			for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
			printf("\n");return 0;
		}
		for(int i=1;i<=n;i++) x[i]>>=1,y[i]>>=1;
	}
	return 0;
}