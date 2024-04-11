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
#define int long long 
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
int n=read(),a[100005];
struct node{
	int f,ch[2];
	int sz_im,sz_im_sqr,sz;
	int ans,ans_im,ans_re;
} s[100005];
inline void pushup(int k){
	s[k].sz=s[s[k].ch[0]].sz+s[s[k].ch[1]].sz+s[k].sz_im;
	s[k].ans_re=s[s[k].ch[0]].ans_re+s[s[k].ch[1]].ans_re+s[k].sz_im*a[k];
	s[k].ans=0;
	s[k].ans+=s[s[k].ch[0]].ans+s[s[k].ch[1]].ans;
	s[k].ans+=s[k].ans_im;
	s[k].ans+=(s[k].sz_im*s[k].sz_im-s[k].sz_im_sqr)*a[k];
	s[k].ans+=s[k].sz_im*s[s[k].ch[1]].sz*a[k]*2;
	s[k].ans+=s[s[k].ch[0]].ans_re*(s[k].sz-s[s[k].ch[0]].sz)*2;
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
	int opx=identify(x);
	int opy=identify(y);
	int u=0;
	if(opx==1)	u=s[x].ch[0];
	if(opx==0)	u=s[x].ch[1];
	connect(u,y,opx);
	connect(y,x,opx^1);
	connect(x,z,opy);
	pushup(y);
	pushup(x);
}
inline void splay(int x){
	while(identify(x)!=-1){
		int up=s[x].f;
		if(identify(up)==-1)				rotate(x);
		else if(identify(up)==identify(x))	rotate(up),rotate(x);
		else								rotate(x),rotate(x);
	}
}
inline void access(int x){
	int y=0;
	while(x){
		splay(x);
		s[x].sz_im+=s[s[x].ch[1]].sz;
		s[x].sz_im_sqr+=s[s[x].ch[1]].sz*s[s[x].ch[1]].sz;
		s[x].ans_im+=s[s[x].ch[1]].ans;
		s[x].ch[1]=y;
		s[x].sz_im-=s[s[x].ch[1]].sz;
		s[x].sz_im_sqr-=s[s[x].ch[1]].sz*s[s[x].ch[1]].sz;
		s[x].ans_im-=s[s[x].ch[1]].ans;
		pushup(x);
		y=x;x=s[x].f;
	}
}
inline void link(int x,int y){
	access(x);splay(x);
	access(y);splay(y);
//	puts("a");
	s[x].f=y;
	s[y].ans_im+=s[x].ans;
	s[y].sz_im+=s[x].sz;
	s[y].sz_im_sqr+=s[x].sz*s[x].sz;
	pushup(y);
}
inline void cut(int x,int y){
	access(y);splay(y);
	splay(x);
	s[y].ans_im-=s[x].ans;
	s[y].sz_im-=s[x].sz;
	s[y].sz_im_sqr-=s[x].sz*s[x].sz;
	s[x].f=0;
	pushup(y);
}
inline bool anc(int x,int y){
	access(y);splay(y);
	splay(x);
	if(identify(y)!=-1)	return 1;
	else				return 0;
}
int fa[100005];
signed main(){
	fz(i,2,n)	fa[i]=read();
	fz(i,1,n)	a[i]=read();
	fz(i,1,n)	s[i].ans=s[i].ans_re=a[i],s[i].sz_im=s[i].sz=1;
	fz(i,2,n)	link(i,fa[i]);
	access(1);splay(1);
//	cout<<s[1].sz_im_sqr<<" "<<s[4].sz_im<<" "<<s[4].sz_im_sqr<<" "<<s[4].sz<<" "<<s[4].ans_re<<" "<<endl;
	printf("%.10lf\n",1.*s[1].ans/n/n);
	int T=read();
	while(T--){
		char opt[15];scanf("%s",opt+1);
		if(opt[1]=='P'){
			int x=read(),y=read();
			if(anc(x,y)){
				if(fa[y])	cut(y,fa[y]);
				fa[y]=x;
				link(y,fa[y]);
			}
			else{
				if(fa[x])	cut(x,fa[x]);
				fa[x]=y;
				if(fa[x])	link(x,fa[x]);
			}
			access(1);splay(1);printf("%.10lf\n",1.*s[1].ans/n/n);
		}
		else{
			int x=read(),y=read();
			access(x);splay(x);a[x]=y;
			pushup(x);
			access(x);splay(x);printf("%.10lf\n",1.*s[x].ans/n/n);
		}
	}
	return 0;
}