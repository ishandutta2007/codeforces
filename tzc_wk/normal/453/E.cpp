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
const int MAXP=MAXN*20;
const int INF=0x3f3f3f3f;
int n,s[MAXN+5],r[MAXN+5],mx[MAXN+5],lim1[MAXN+5],lim2[MAXN+5];
int key1[MAXN+5],key2[MAXN+5],uni1[MAXN+5],uni2[MAXN+5],num1=0,num2=0;
struct seg2d{
	struct node{int ch[2];ll sum;} s[MAXP+5];
	int rt[MAXN+5],ncnt;
	seg2d(){ncnt=0;memset(rt,0,sizeof(rt));}
	void add_in(int &k,int l,int r,int x,int v){
		if(!k) k=++ncnt;s[k].sum+=v;
		if(l==r) return;int mid=l+r>>1;
		if(x<=mid) add_in(s[k].ch[0],l,mid,x,v);
		else add_in(s[k].ch[1],mid+1,r,x,v);
	}
	ll query_in(int k,int l,int r,int ql,int qr){
		if(ql>qr||!k) return 0;int mid=l+r>>1;
		if(ql<=l&&r<=qr) return s[k].sum;
		if(qr<=mid) return query_in(s[k].ch[0],l,mid,ql,qr);
		else if(ql>mid) return query_in(s[k].ch[1],mid+1,r,ql,qr);
		else return query_in(s[k].ch[0],l,mid,ql,mid)+query_in(s[k].ch[1],mid+1,r,mid+1,qr);
	}
	void add_out(int x,int p,int v){
		for(int i=x;i<=n;i+=(i&(-i))) add_in(rt[i],1,max(num1,num2),p,v);
	}
	ll query_out(int x,int l,int r){
		ll ret=0;
		for(int i=x;i;i&=(i-1)) ret+=query_in(rt[i],1,max(num1,num2),l,r);
		return ret;
	}
	ll query(int l1,int r1,int l2,int r2){return query_out(r1,l2,r2)-query_out(l1-1,l2,r2);}
} t_s,t_r,t_m,T_r,T_m;
set<int> fst;
struct event{
	int l,r,t;
	event(int _l=0,int _r=0,int _t=0):l(_l),r(_r),t(_t){}
	bool operator <(const event &rhs) const{return l<rhs.l;}
};
set<event> st;
void split(int x){
	if(st.empty()) return;
	set<event>::iterator it=st.lower_bound(event(x+1,0,0));
	if(it==st.begin()) return;
	--it;event val=*it;if(val.r<=x) return;
	st.erase(st.find(val));
	st.insert(event(val.l,x,val.t));
	st.insert(event(x+1,val.r,val.t));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&s[i],&mx[i],&r[i]);
	for(int i=1;i<=n;i++){
		if(r[i]){
			lim1[i]=mx[i]/r[i];
			lim2[i]=(mx[i]-s[i])/r[i];
		} else lim1[i]=lim2[i]=INF;
	}
	for(int i=1;i<=n;i++) key1[i]=lim1[i],key2[i]=lim2[i];
	sort(key1+1,key1+n+1);sort(key2+1,key2+n+1);key1[0]=-INF;key2[0]=-INF;
	for(int i=1;i<=n;i++) if(key1[i-1]!=key1[i]) uni1[++num1]=key1[i];
	for(int i=1;i<=n;i++) if(key2[i-1]!=key2[i]) uni2[++num2]=key2[i];
	for(int i=1;i<=n;i++){
		lim1[i]=lower_bound(uni1+1,uni1+num1+1,lim1[i])-uni1;//remember to unique
		lim2[i]=lower_bound(uni2+1,uni2+num2+1,lim2[i])-uni2;
//		printf("%d %d\n",lim1[i],lim2[i]);
	}
	for(int i=1;i<=n;i++) fst.insert(i);
	for(int i=1;i<=n;i++){
		t_s.add_out(i,lim2[i],s[i]);
		t_r.add_out(i,lim2[i],r[i]);
		t_m.add_out(i,lim2[i],mx[i]);
	} int qu;scanf("%d",&qu);
	while(qu--){
		int t,L,R;scanf("%d%d%d",&t,&L,&R);
		int pos=lower_bound(uni2+1,uni2+num2+1,t)-uni2;
		ll sums=t_s.query(L,R,pos,num2);
		ll sumr=t_r.query(L,R,pos,num2);
		ll summ=t_m.query(L,R,1,pos-1);
//		printf("%d %lld %lld %lld\n",pos,sums,sumr,summ);
//		printf("%lld\n",summ+sums+sumr*t);
		ll sum=summ+sums+sumr*t;
		if(L!=1) split(L-1);split(R);
		while(1){
			set<event>::iterator it=st.lower_bound(event(L,0,0));
			if(it==st.end()||(it->l)>R) break;event val=*it;
			int pp=lower_bound(uni1+1,uni1+num1+1,t-val.t)-uni1;
			ll ssumr=T_r.query(val.l,val.r,pp,num1);
			ll ssumm=T_m.query(val.l,val.r,1,pp-1);
//			printf("%d %d %d %d\n",val.l,val.r,t-val.t,pp);
//			printf("%lld %lld\n",ssumr,ssumm);
			sum+=ssumm+ssumr*(t-val.t);st.erase(st.find(val));
		} st.insert(event(L,R,t));
		while(1){
			set<int>::iterator it=fst.lower_bound(L);
			if(it==fst.end()||(*it)>R) break;
			int x=(*it);
			t_s.add_out(x,lim2[x],-s[x]);
			t_r.add_out(x,lim2[x],-r[x]);
			t_m.add_out(x,lim2[x],-mx[x]);
			T_r.add_out(x,lim1[x],r[x]);
			T_m.add_out(x,lim1[x],mx[x]);
			fst.erase(fst.find(x));
		} printf("%lld\n",sum);
	}
	return 0;
}
/*
10
0 4 2
0 3 0
0 96 7
0 25 9
0 90 4
0 93 5
0 87 3
0 58 3
0 65 8
0 30 0
10
3 3 4
10 1 7
11 8 9
19 4 9
28 3 10
33 5 10
38 4 5
45 5 7
48 5 9
58 1 4
*/