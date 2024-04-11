//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),m=read();
int offset=0;
struct node{
	int f,ch[2],lz;
	int sz,im_sz;
	int val,which;
} s[400005];
inline void pushup(int k){
//	s[0].sz=s[0].im_sz=s[0].lz=0;
	if(!k)	return;
	s[k].sz=s[s[k].ch[0]].sz+s[s[k].ch[1]].sz+((k>n)?0:1)+s[k].im_sz;
	s[k].which=k;
	if(s[s[s[k].ch[0]].which].val>s[s[k].which].val)	s[k].which=s[s[k].ch[0]].which;
	if(s[s[s[k].ch[1]].which].val>s[s[k].which].val)	s[k].which=s[s[k].ch[1]].which;
}
inline void pushdown(int k){
	if(s[k].lz){
		swap(s[k].ch[0],s[k].ch[1]);
		if(s[k].ch[0])	s[s[k].ch[0]].lz^=1;
		if(s[k].ch[1])	s[s[k].ch[1]].lz^=1;
		s[k].lz=0;
	}
}
inline int identify(int k){
	if(s[s[k].f].ch[0]==k)	return 0;
	if(s[s[k].f].ch[1]==k)	return 1;
	return -1;
}
inline void connect(int k,int f,int op){
	s[k].f=f;
	if(op==-1)	return;
	s[f].ch[op]=k;
}
inline void rotate(int x){
	int y=s[x].f;
	int z=s[y].f;
	int opy=identify(y);
	int opx=identify(x);
	int u=0;
	if(opx==1)		u=s[x].ch[0];
	if(opx==0)		u=s[x].ch[1];
	connect(u,y,opx);
	connect(y,x,opx^1);
	connect(x,z,opy);
	pushup(y);
	pushup(x);
	pushup(z);
}
inline void pushall(int x){
	if(identify(x)!=-1)	pushall(s[x].f);
	pushdown(x);
}
inline void splay(int x){
	pushall(x);
	while(identify(x)!=-1){
		int up=s[x].f;
//		cout<<x<<" "<<up<<endl;
		if(identify(up)==-1)				rotate(x);
		else if(identify(up)==identify(x))	rotate(up),rotate(x);
		else								rotate(x),rotate(x);
	}
}
inline void access(int x){
	int y=0;
	while(x){
//		cout<<x<<endl;
		splay(x);
		s[x].im_sz+=s[s[x].ch[1]].sz-s[y].sz;
		s[x].ch[1]=y;
		pushup(x);y=x;x=s[x].f;
	}
}
inline void makeroot(int x){
	access(x);splay(x);
	swap(s[x].ch[0],s[x].ch[1]);
	if(s[x].ch[0])	s[s[x].ch[0]].lz^=1;
	if(s[x].ch[1])	s[s[x].ch[1]].lz^=1;
}
inline int findroot(int x){
	access(x);splay(x);
	while(s[x].ch[0]){
		pushdown(x);
		x=s[x].ch[0];
	}
	splay(x);
	return x;
}
inline void split(int x,int y){
	makeroot(x);
	access(y);splay(y);
}
inline void link(int x,int y){
//	cout<<"link "<<x<<" "<<y<<endl;
	makeroot(x);makeroot(y);
	offset-=(s[x].sz&1);
	offset-=(s[y].sz&1);
	s[x].f=y;
	s[y].im_sz+=s[x].sz;
	pushup(y);
	offset+=(s[y].sz&1);
}
inline void cut(int x,int y){
//	cout<<"cut "<<x<<" "<<y<<endl;
	split(x,y);
	offset-=(s[y].sz&1);
	s[x].f=s[y].ch[0]=0;
	pushup(y);
	offset+=(s[x].sz&1);
	offset+=(s[y].sz&1);
}
int u[300005],v[300005],w[300005];
priority_queue<pii> pq;
inline void insert(int _,int a,int b,int c){
	if(findroot(a)==findroot(b)){
		split(a,b);
		int ind=s[b].which;
		if(s[ind].val>c){
			cut(u[ind-n],ind);
			cut(v[ind-n],ind);
			s[_+n].which=_+n;
			s[_+n].val=c;
			s[_+n].sz=1;
			link(a,_+n);
			link(b,_+n);
			pq.push({c,_});
		}
	}
	else{
		s[_+n].which=_+n;
		s[_+n].val=c;
		s[_+n].sz=1;
		link(a,_+n);
		link(b,_+n);
		pq.push({c,_});
	}
	if(offset){
		puts("-1");
		return;
	}
	else{
		while(!pq.empty()){
			pii p=pq.top();pq.pop();
			int ind=p.se;
			cut(u[ind],ind+n);
			cut(v[ind],ind+n);
//			cout<<offset<<endl;
			if(offset){
				link(u[ind],ind+n);
				link(v[ind],ind+n);
				pq.push({w[ind],ind});
				cout<<w[ind]<<endl;
				return;
			}
		}
		puts("0");
	}
}
signed main(){
	offset=n;
	fz(i,1,n)	s[i].sz=1,s[i].which=i;
	fz(i,1,m){
		u[i]=read(),v[i]=read(),w[i]=read();
		insert(i,u[i],v[i],w[i]);
	}
	return 0;
}