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
#define y0 y101010101010
#define y1 y010101010101
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
const int MOD=1e9+7;
const int INV2=5e8+4;
int sum(int l,int r){return 1ll*(l+r)*(r-l+1)%MOD*INV2%MOD;}
int calc(int l1,int r1,int l2,int r2,int k){
	if((r1-l1+1)<(r2-l2+1)) l1^=l2^=l1^=l2,r1^=r2^=r1^=r2;
	int tl=(l1^l2)&~(r1-l1),tr=min(tl+r1-l1,k-1);
	if(tl>k-1) return 0;return 1ll*(r2-l2+1)*sum(tl+1,tr+1)%MOD;
}
int solve(int x,int y,int k){
	int ans=0;
	for(int i=x;i;i&=(i-1)) for(int j=y;j;j&=(j-1))
		ans=(ans+calc(i&(i-1),i-1,j&(j-1),j-1,k))%MOD;
//	printf("%d %d %d %d\n",x,y,k,ans);
	return ans;
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--){
		int x1,y1,x2,y2,k;scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&k);
		printf("%d\n",((solve(x2,y2,k)-solve(x2,y1-1,k)-solve(x1-1,y2,k)+solve(x1-1,y1-1,k))%MOD+MOD)%MOD);
	}
	return 0;
}
/*
1
6 3 9 5 1
*/