//Created time: 2022/3/13 20:54:05
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
const int MAXN=2e5;
const int MAXV=2e5+1;
const int MAXP=MAXN<<6;
int n,qu,c[MAXN+5],r[MAXN+5],tim[MAXN+5];
struct seg{
	int l,r,lst,hav;
	seg(){l=r=lst=hav=0;}
	seg(int _l,int _r,int _lst,int _hav){l=_l;r=_r;lst=_lst;hav=_hav;}
	bool operator <(const seg &rhs) const{return mt(l,r,lst,hav)<mt(rhs.l,rhs.r,rhs.lst,rhs.hav);}
};
set<seg> st;
struct node{int ch[2];ll sumc,sumr;} s[MAXP+5];
int rt[MAXN+5],ncnt;
int insert(int k,int l,int r,int p,int C,int R){
	int z=++ncnt;s[z]=s[k];s[z].sumc+=C;s[z].sumr+=R;
	if(l==r) return z;int mid=l+r>>1;
	if(p<=mid) s[z].ch[0]=insert(s[k].ch[0],l,mid,p,C,R);
	else s[z].ch[1]=insert(s[k].ch[1],mid+1,r,p,C,R);
	return z;
}
ll queryr(int k,int l,int r,int ql,int qr){
	if(!k) return 0;
	if(ql<=l&&r<=qr) return s[k].sumr;int mid=l+r>>1;
	if(qr<=mid) return queryr(s[k].ch[0],l,mid,ql,qr);
	else if(ql>mid) return queryr(s[k].ch[1],mid+1,r,ql,qr);
	else return queryr(s[k].ch[0],l,mid,ql,mid)+queryr(s[k].ch[1],mid+1,r,mid+1,qr);
}
ll queryc(int k,int l,int r,int ql,int qr){
	if(!k) return 0;
	if(ql<=l&&r<=qr) return s[k].sumc;int mid=l+r>>1;
	if(qr<=mid) return queryc(s[k].ch[0],l,mid,ql,qr);
	else if(ql>mid) return queryc(s[k].ch[1],mid+1,r,ql,qr);
	else return queryc(s[k].ch[0],l,mid,ql,mid)+queryc(s[k].ch[1],mid+1,r,mid+1,qr);
}
ll calc_nd(int L,int R,int dif){
//	ll sum=0;
//	for(int i=L;i<=R;i++) sum+=min((ll)c[i],1ll*dif*r[i]);
//	return sum;
	ll A=queryc(rt[R],0,MAXV,0,dif)-queryc(rt[L-1],0,MAXV,0,dif);
	ll B=queryr(rt[R],0,MAXV,dif+1,MAXV)-queryr(rt[L-1],0,MAXV,dif+1,MAXV);
	return A+B*dif;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&r[i]),tim[i]=min((c[i]+r[i]-1)/r[i],MAXV);
	for(int i=1;i<=n;i++) rt[i]=insert(rt[i-1],0,MAXV,tim[i],c[i],r[i]);
	scanf("%d",&qu);ll res=0;
	for(int i=1;i<=n;i++) st.insert(seg(i,i,0,c[i]));
	while(qu--){
		int T;ll H;scanf("%d%lld",&T,&H);bool flg=0;
		while(!st.empty()){
			seg cur=*st.begin();st.erase(st.find(cur));
//			if(qu==707) printf("! %d %d %d %d\n",cur.l,cur.r,cur.lst,cur.hav);
			if(cur.hav!=0){
				assert(cur.l==cur.r);
				ll cur_num=min((ll)(c[cur.l]),cur.hav+1ll*(T-cur.lst)*r[cur.l]);
				if(cur_num<=H) H-=cur_num;
				else{
					cur_num-=H;
					if(cur.l!=1) st.insert(seg(1,cur.l-1,T,0));
					st.insert(seg(cur.l,cur.r,T,cur_num));flg=1;
					H=0;break;
				}
			} else {
				if(H>=calc_nd(cur.l,cur.r,T-cur.lst)) H-=calc_nd(cur.l,cur.r,T-cur.lst);
				else{
					int L=cur.l,R=cur.r,p=cur.l-1;
					while(L<=R){
						int mid=L+R>>1;
						if(calc_nd(cur.l,mid,T-cur.lst)<=H) p=mid,L=mid+1;
						else R=mid-1;
					}
					++p;
					if(p!=cur.l) H-=calc_nd(cur.l,p-1,T-cur.lst);
					int curp=min((ll)c[p],1ll*r[p]*(T-cur.lst));
					if(p!=1) st.insert(seg(1,p-1,T,0));
//					if(qu==707) printf("! %d %lld\n",p,curp-H);
					st.insert(seg(p,p,T,curp-H));
					if(p!=cur.r) st.insert(seg(p+1,cur.r,cur.lst,0));
					flg=1;H=0;break;
				}
			}
		}
//		if(qu==706) cerr<<H<<endl;
		if(!flg) res+=H,st.insert(seg(1,n,T,0));
	}
	printf("%lld\n",res);
	return 0;
}
/*
5
10 1
17 2
19 3
20 1
15 4
5
1 100
4 50
8 120
13 90
15 40
*/