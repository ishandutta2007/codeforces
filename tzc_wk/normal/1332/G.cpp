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
const int MAXN=2e5;
const int LOG_N=17;
const int INF=0x3f3f3f3f;
int n,qu,a[MAXN+5],L[MAXN+5],R[MAXN+5];
vector<pii> ql[MAXN+5];
int mnl[MAXN+5],mxl[MAXN+5],mnr[MAXN+5],mxr[MAXN+5];
namespace solve3{
	vector<pii> pl[MAXN+5];
	tuple<int,int,int> ans[MAXN+5];
	struct node{int l,r;pii val;} s[MAXN*4+5];
	pii merge(pii x,pii y){
		pii ret;ret.fi=min(x.fi,y.fi);
		if(ret.fi==x.fi) ret.se=x.se;
		else ret.se=y.se;
		return ret;
	}
	void pushup(int k){s[k].val=merge(s[k<<1].val,s[k<<1|1].val);}
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;if(l==r){s[k].val=mp(INF,l);return;}
		int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
	}
	void modify(int k,int x,int v){
		if(s[k].l==s[k].r) return chkmin(s[k].val.fi,v),void();
		int mid=s[k].l+s[k].r>>1;
		(x<=mid)?modify(k<<1,x,v):modify(k<<1|1,x,v);
		pushup(k);
	}
	pii query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r) return s[k].val;
		int mid=s[k].l+s[k].r>>1;
		if(r<=mid) return query(k<<1,l,r);
		else if(l>mid) return query(k<<1|1,l,r);
		else return merge(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
	}
	void solve(){
		build(1,1,n);
		for(int i=1;i<=n;i++) pl[mxl[i]].pb(mp(i,mxr[i]));
		for(int i=1;i<=n;i++) pl[mnl[i]].pb(mp(i,mnr[i]));
//		for(int i=1;i<=n;i++) printf("%d %d %d %d\n",mnl[i],mxl[i],mnr[i],mxr[i]);
		for(int i=n;i;i--){
			for(pii p:pl[i]) modify(1,p.fi,p.se);
			for(pii p:ql[i]){
				int x=p.fi,id=p.se;
				pii mn=query(1,i,x);
				if(mn.fi<=x){
					int pos=mn.se;
					if(mnl[pos]>=i&&mnr[pos]<=x) ans[id]=make_tuple(mnl[pos],pos,mnr[pos]);
					if(mxl[pos]>=i&&mxr[pos]<=x) ans[id]=make_tuple(mxl[pos],pos,mxr[pos]);
				}
			}
		}
	}
}
namespace solve4{
	template<typename T> struct st_table{
		T v[MAXN+5][LOG_N+2];int op;
		void build(){
			for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n;j++)
				v[j][i]=(op)?max(v[j][i-1],v[j+(1<<i-1)][i-1]):min(v[j][i-1],v[j+(1<<i-1)][i-1]);
		}
		T query(int l,int r){
			int k=31-__builtin_clz(r-l+1);
			return (op)?max(v[l][k],v[r-(1<<k)+1][k]):min(v[l][k],v[r-(1<<k)+1][k]);
		}
	};
	st_table<int> st3;
	st_table<pii> mn,mx,st4;
	int l3[MAXN+5],r3[MAXN+5],r4[MAXN+5];
	tuple<int,int,int,int> ans[MAXN+5];
	void solve(){
		mx.op=st3.op=1;
		for(int i=1;i<=n;i++) mn.v[i][0]=mx.v[i][0]=mp(a[i],i);
		mn.build();mx.build();
		for(int i=1;i<=n;i++){
			r3[i]=max(mxr[i],mnr[i]);
			l3[i]=min(mxl[i],mnl[i]);
			st3.v[i][0]=l3[i];
		} st3.build();
		for(int i=1;i<=n;i++){
			int l=r3[i]+1,r=n,p=n+1;
			while(l<=r){
				int mid=l+r>>1;
				if(st3.query(r3[i]+1,mid)>i) p=mid,r=mid-1;
				else l=mid+1;
			} r4[i]=p;st4.v[i][0]=mp(r4[i],i);
//			printf("%d\n",r4[i]);
		} st4.build();
		for(int i=1;i<=qu;i++){
			pii p=st4.query(L[i],R[i]);
//			printf("%d\n",p.fi);
			if(p.fi<=R[i]){
				int i1=p.se,i4=p.fi;
				int i2=mn.query(i1,i4).se,i3=mx.query(i1,i4).se;
				if(i2>i3) i2^=i3^=i2^=i3;
//				printf("%d %d %d %d\n",i1,i2,i3,i4);
				ans[i]=make_tuple(i1,i2,i3,i4);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	stack<int> stk;
	for(int i=1;i<=n;i++){
		while(!stk.empty()&&a[stk.top()]<=a[i]) stk.pop();
		mxl[i]=((stk.empty())?0:stk.top());stk.push(i);
	} while(!stk.empty()) stk.pop();
	for(int i=1;i<=n;i++){
		while(!stk.empty()&&a[stk.top()]>=a[i]) stk.pop();
		mnl[i]=((stk.empty())?0:stk.top());stk.push(i);
	} while(!stk.empty()) stk.pop();
	for(int i=n;i;i--){
		while(!stk.empty()&&a[stk.top()]<=a[i]) stk.pop();
		mxr[i]=((stk.empty())?n+1:stk.top());stk.push(i);
	} while(!stk.empty()) stk.pop();
	for(int i=n;i;i--){
		while(!stk.empty()&&a[stk.top()]>=a[i]) stk.pop();
		mnr[i]=((stk.empty())?n+1:stk.top());stk.push(i);
	} while(!stk.empty()) stk.pop();
	for(int i=1;i<=qu;i++) scanf("%d%d",&L[i],&R[i]),ql[L[i]].pb(mp(R[i],i));
	solve3::solve();solve4::solve();
	for(int i=1;i<=qu;i++){
		if(!get<0>(solve3::ans[i])) printf("0\n");
		else if(!get<0>(solve4::ans[i]))
			printf("3\n%d %d %d\n",get<0>(solve3::ans[i]),get<1>(solve3::ans[i]),get<2>(solve3::ans[i]));
		else printf("4\n%d %d %d %d\n",get<0>(solve4::ans[i]),get<1>(solve4::ans[i]),get<2>(solve4::ans[i]),get<3>(solve4::ans[i]));
	}
	return 0;
}