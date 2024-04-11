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
const int MAXN=1e5;
int n,m;
struct event{
	int x,y,id;
	bool operator <(const event &rhs) const{
		if(x!=rhs.x) return x<rhs.x;
		else if(y!=rhs.y) return y<rhs.y;
		return id<rhs.id;
	}
} a[MAXN*2+5];
int key[MAXN*2+5],uni[MAXN*2+5],cnt=0,num=0;
int get(int x){return lower_bound(uni+1,uni+num+1,x)-uni;}
bool is[MAXN*2+5],ans[MAXN+5];int c1=0,lst=0;
int t[MAXN*2+5];
void add(int x){for(int i=x;i<=num;i+=(i&-i)) t[i]++;};
int query(int x){int ret=0;for(int i=x;i;i&=(i-1)) ret+=t[i];return ret;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y),key[++cnt]=a[i].y;
	for(int i=1;i<=m;i++) scanf("%d%d",&a[i+n].x,&a[i+n].y),a[i+n].id=i,key[++cnt]=a[i+n].y;
	sort(a+1,a+n+m+1);sort(key+1,key+cnt+1);key[0]=-1;
	for(int i=1;i<=cnt;i++) if(key[i]!=key[i-1]) uni[++num]=key[i];
	for(int i=1;i<=n+m;i++){
		int pos=get(a[i].y);
		if(a[i].id){
			if(a[i-1].x==a[i].x&&a[i-1].y==a[i].y) ans[a[i].id]=1;
			else if(a[i].x!=lst&&!is[pos]){
				int dif=query(pos)-c1;
//				printf("%d\n",dif);
				if(a[i].y==a[i].x+dif) ans[a[i].id]=1;
			}
		} else {
			int dif=query(pos)-c1;
			if(a[i].x+dif<a[i].y){//up
				if(!is[pos]) add(pos),is[pos]=1;
			} else if(a[i].x+dif>a[i].y){//down
				if(lst!=a[i].x) lst=a[i].x,c1++;
			}
		}
	}
	for(int i=1;i<=m;i++) printf("%s\n",(ans[i])?"LOSE":"WIN");
	return 0;
}