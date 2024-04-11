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
int n,tmp;
int c[3];
int main(){
	scanf("%d",&n);scanf("%d",&tmp);
	for(int i=1;i<=3;i++) if(i^tmp){c[0]=i;break;}
	printf("%d %d %d\n",c[0],1,1);fflush(stdout);scanf("%d",&tmp);
	for(int i=1;i<=3;i++) if((i^tmp)&&(i^c[0])){c[1]=i;break;}
	printf("%d %d %d\n",c[1],1,2);fflush(stdout);
	for(int i=1;i<=3;i++) if((i^c[0])&&(i^c[1])) c[2]=i;
	vector<pii> blk,wht;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		if(((i+j)&1)&&(i!=1||j!=2)) blk.pb(mp(i,j));
		else if(!((i+j)&1)&&(i!=1||j!=1)) wht.pb(mp(i,j));
	}
	for(int i=3;i<=n*n;i++){
		int tmp;scanf("%d",&tmp);
		if(tmp==c[0]){
			if(blk.empty()){
				pii pp=wht.back();wht.pop_back();
				printf("%d %d %d\n",c[2],pp.fi,pp.se);
				fflush(stdout);
			} else {
				pii pp=blk.back();blk.pop_back();
				printf("%d %d %d\n",c[1],pp.fi,pp.se);
				fflush(stdout);
			}
		} else if(tmp==c[1]) {
			if(wht.empty()){
				pii pp=blk.back();blk.pop_back();
				printf("%d %d %d\n",c[2],pp.fi,pp.se);
				fflush(stdout);
			} else {
				pii pp=wht.back();wht.pop_back();
				printf("%d %d %d\n",c[0],pp.fi,pp.se);
				fflush(stdout);
			}
		} else {
			if(!wht.empty()){
				pii pp=wht.back();wht.pop_back();
				printf("%d %d %d\n",c[0],pp.fi,pp.se);
				fflush(stdout);
			} else {
				pii pp=blk.back();blk.pop_back();
				printf("%d %d %d\n",c[1],pp.fi,pp.se);
				fflush(stdout);
			}
		}
	}
	return 0;
}