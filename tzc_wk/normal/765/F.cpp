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
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int INF=0x3f3f3f3f;
const int MAXM=3e5;
int n,qu,a[MAXN+5],res[MAXM+5];
struct qry{
	int l,r,id;
	bool operator <(const qry &rhs){
		return r<rhs.r;
	}
} q[MAXM+5];
struct node{int l,r,mn;vector<int> t;} s[MAXN*4+5];
void pushup(int k){s[k].mn=min(s[k].mn,min(s[k<<1].mn,s[k<<1|1].mn));}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].mn=INF;
	for(int i=l;i<=r;i++) s[k].t.pb(a[i]);
	sort(s[k].t.begin(),s[k].t.end());
	if(l==r) return;int mid=l+r>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
int mn;
void modify(int k,int p,int v){
	if(s[k].r<=p){
		vector<int>::iterator it=lower_bound(s[k].t.begin(),s[k].t.end(),v);
		if(it!=s[k].t.end()) chkmin(s[k].mn,abs((*it)-v));
		if(it!=s[k].t.begin()) chkmin(s[k].mn,abs((*(it-1))-v));
//		if(it!=s[k].t.end()) printf("%d\n",(*it));
//		printf("%d %d\n",k,s[k].mn);
		if(s[k].mn>=mn) return;
		if(s[k].l==s[k].r) return chkmin(mn,s[k].mn),void();
	} int mid=s[k].l+s[k].r>>1;
	if(p>mid) modify(k<<1|1,p,v);
	modify(k<<1,p,v);
	pushup(k);chkmin(mn,s[k].mn);
}
int query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].mn;
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return min(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
}
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&a[i]);scanf("%d",&qu);
	for(int i=1;i<=qu;i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+qu+1);build(1,1,n);
	for(int i=1,c=1;i<=n;i++){
		mn=INF;if(i!=1) modify(1,i-1,a[i]);
		while(q[c].r==i){
			res[q[c].id]=query(1,q[c].l,i-1);
			c++;
		}
	} for(int i=1;i<=qu;i++) printf("%d\n",res[i]);
	return 0;
}