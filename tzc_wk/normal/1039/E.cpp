//Created time: 2022/3/22 12:35:07
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
#ifdef FASTIO
#define FILE_SIZE 1<<23
char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
inline void putc(char x){(*p3++=x);}
template<typename T> void read(T &x){
	x=0;char c=getc();T neg=0;
	while(!isdigit(c)) neg|=(c=='-'),c=getc();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c-'0'),c=getc();
	if(neg) x=-x;
}
template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=-x;recursive_print(x);}
template<typename T> void print(T x,char c){print(x);putc(c);}
void readstr(char *s){
	char c=getc();
	while(c<=32||c>=127) c=getc();
	while(c>32&&c<127) s[0]=c,s++,c=getc();
	(*s)=0;
}
void printstr(string s){for(int i=0;i<s.size();i++) putc(s[i]);}
void printstr(char *s){int len=strlen(s);for(int i=0;i<len;i++) putc(s[i]);}
void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
#endif
const int MAXN=1e5;
const int LOG_N=18;
const int BLK=316;
int n,qu,W,a[MAXN+5],res[MAXN+5];
struct qry{
	int k,id;
	friend bool operator <(const qry &X,const qry &Y){return X.k<Y.k;}
} q[MAXN+5];
int mn[LOG_N+2][MAXN+5],mx[LOG_N+2][MAXN+5],hib[MAXN+5];
int query_mn(int l,int r){
	int k=hib[r-l+1];
	return min(mn[k][l],mn[k][r-(1<<k)+1]);
}
int query_mx(int l,int r){
	int k=hib[r-l+1];
	return max(mx[k][l],mx[k][r-(1<<k)+1]);
}
vector<int> add[MAXN+5];
int findgeq(int K){
	int l=1,r=qu,p=qu+1;
	while(l<=r){
		int mid=l+r>>1;
		if(q[mid].k>=K) p=mid,r=mid-1;
		else l=mid+1;
	}
	return p;
}
int findnxt(int x,int K){
	int L=x,R=n,p=x;
	while(L<=R){
		int mid=L+R>>1;
		if(query_mx(x,mid)-query_mn(x,mid)<=K) p=mid,L=mid+1;
		else R=mid-1;
	}
	return p;
}
struct node{int ch[2],f,siz;} s[MAXN+5];
void pushup(int k){s[k].siz=s[s[k].ch[0]].siz+s[s[k].ch[1]].siz+(k<=n);}
int ident(int k){return ((s[s[k].f].ch[0]==k)?0:((s[s[k].f].ch[1]==k)?1:-1));}
void connect(int k,int f,int op){s[k].f=f;if(~op) s[f].ch[op]=k;}
void rotate(int x){
	int y=s[x].f,z=s[y].f,dx=ident(x),dy=ident(y);
	connect(s[x].ch[dx^1],y,dx);connect(y,x,dx^1);connect(x,z,dy);
	pushup(y);pushup(x);
}
void splay(int k){
	while(~ident(k)){
		if(ident(s[k].f)==-1) rotate(k);
		else if(ident(k)==ident(s[k].f)) rotate(s[k].f),rotate(k);
		else rotate(k),rotate(k);
	}
}
void access(int k){for(int pre=0;k;pre=k,k=s[k].f) splay(k),s[k].ch[1]=pre,pushup(k);}
void link(int x,int f){/*printf("link %d %d\n",x,f);*/access(x);splay(x);s[x].f=f;}
void cut(int x){/*printf("cut %d\n",x);*/access(x);splay(x);s[s[x].ch[0]].f=0;s[x].ch[0]=0;pushup(x);}
int main(){
	scanf("%d%d%d",&n,&W,&qu);
	for(int i=2;i<=MAXN;i++) hib[i]=hib[i>>1]+1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),mn[0][i]=mx[0][i]=a[i];
	for(int i=1;i<=qu;i++) scanf("%d",&q[i].k),q[i].id=i,q[i].k=W-q[i].k;
	sort(q+1,q+qu+1);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n;j++){
		mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<i-1)]);
		mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<i-1)]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=min(i+BLK+1,n);j++){
			int dif=query_mx(i,j)-query_mn(i,j);
			int pos=findgeq(dif);
			if(pos!=qu+1) add[pos].pb(i);
		}
	}
	for(int i=1;i<=qu;i++){
		sort(add[i].begin(),add[i].end());
		add[i].resize(unique(add[i].begin(),add[i].end())-add[i].begin());
	}
	for(int i=1;i<=n;i++) s[i].siz=1;
	for(int i=1;i<=qu;i++){
//		printf("query %d\n",i);
		for(int id:add[i]){
			cut(id);int pos=findnxt(id,q[i].k)+1;
			if(pos-id<=BLK) link(id,pos);
		}
		int cur=1,sum=0;
		while(cur<=n){
//			printf("%d\n",cur);
			access(cur);splay(cur);sum+=s[cur].siz-1;
			int R=cur;while(s[R].ch[0]) R=s[R].ch[0];
			splay(R);cur=findnxt(R,q[i].k)+1;sum++;
		}
		res[q[i].id]=sum-1;
	}
	for(int i=1;i<=qu;i++) printf("%d\n",res[i]);
	return 0;
}