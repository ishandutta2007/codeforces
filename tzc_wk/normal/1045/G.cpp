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
const int MAXN=1e5;
int n,k,key[MAXN+5],uni[MAXN+5],num=0;
struct robot{int x,len,q;} a[MAXN+5];
bool cmp1(robot lhs,robot rhs){return lhs.len>rhs.len;}
bool cmp2(robot lhs,robot rhs){return lhs.q<rhs.q;}
int t[MAXN+5];ll ans=0;
void add(int x,int v){for(int i=x;i<=num;i+=(i&(-i))) t[i]+=v;}
int query(int x){int ret=0;for(int i=x;i;i&=(i-1)) ret+=t[i];return ret;}
int query(int l,int r){return query(r)-query(l-1);}
void cdq(int l,int r){
	if(l==r) return;int mid=l+r>>1;
	cdq(l,mid);cdq(mid+1,r);int pl=l,pr=l;
	for(int i=mid+1;i<=r;i++){
		while(a[pr].q<=a[i].q+k&&pr<=mid){
			int pos=lower_bound(uni+1,uni+num+1,a[pr].x)-uni;
			add(pos,1);++pr;
		}
		while(a[pl].q<a[i].q-k&&pl<=mid){
			int pos=lower_bound(uni+1,uni+num+1,a[pl].x)-uni;
			add(pos,-1);++pl;
		}
		int l=lower_bound(uni+1,uni+num+1,a[i].x-a[i].len)-uni;
		int r=upper_bound(uni+1,uni+num+1,a[i].x+a[i].len)-uni-1;
		ans+=query(l,r);
	}
	for(int i=pl;i<pr;i++){
		int pos=lower_bound(uni+1,uni+num+1,a[i].x)-uni;
		add(pos,-1);
	} sort(a+l,a+r+1,cmp2);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].len,&a[i].q);
		key[i]=a[i].x;
	} key[0]=-1;sort(key+1,key+n+1);sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++) if(key[i]^key[i-1]) uni[++num]=key[i];
//	for(int i=1;i<=n;i++){
//		int l=lower_bound(uni+1,uni+num+1,a[i].x-a[i].len)-uni;
//		int r=upper_bound(uni+1,uni+num+1,a[i].x+a[i].len)-uni-1;
//		printf("%d %d\n",l,r);
//	}
	cdq(1,n);printf("%lld\n",ans);
	return 0;
}