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
struct node{
	int ch[2],val,key,sz,lz;
} s[300005];
int cnt=0,root=0;
inline void pushup(int k){
	s[k].sz=s[s[k].ch[0]].sz+s[s[k].ch[1]].sz+1;
}
inline void pushdown(int k){
	if(s[k].lz){
		if(s[k].ch[0])	s[s[k].ch[0]].val+=s[k].lz,s[s[k].ch[0]].lz+=s[k].lz;
		if(s[k].ch[1])	s[s[k].ch[1]].val+=s[k].lz,s[s[k].ch[1]].lz+=s[k].lz;
		s[k].lz=0;
	}
}
inline void split(int k,int val,int &a,int &b){//<=val,>val
//	cout<<k<<" "<<s[k].ch[0]<<" "<<s[k].ch[1]<<endl;
	if(!k){
		a=b=0;return;
	}
	pushdown(k);
	if(val<s[k].val)	b=k,split(s[k].ch[0],val,a,s[k].ch[0]);
	else				a=k,split(s[k].ch[1],val,s[k].ch[1],b);
	pushup(k);
}
inline int merge(int a,int b){//subtree a<subtree b
	if(!a||!b){
		return a+b;
	}
	pushdown(a);pushdown(b);
	if(s[a].key<s[b].key){
		s[a].ch[1]=merge(s[a].ch[1],b);
		pushup(a);
		return a;
	}
	else{
		s[b].ch[0]=merge(a,s[b].ch[0]);
		pushup(b);
		return b;
	}
}
inline int newnode(int val){
	s[++cnt].ch[0]=s[cnt].ch[1]=0;
	s[cnt].key=(rand()<<15|rand());
	s[cnt].sz=1;
	s[cnt].lz=0;
	s[cnt].val=val;
	return cnt;
}
inline void insert(int val){
//	cout<<"insert "<<val<<endl;
	int k1,k2;
	split(root,val,k1,k2);
	root=merge(merge(k1,newnode(val)),k2);
}
inline void del(int val){
//	cout<<"del "<<val<<endl;
	int k1,k2,k3;
	split(root,val,k1,k3);
	split(k1,val-1,k1,k2);
	int ls=s[k2].ch[0],rs=s[k2].ch[1];
	k2=merge(ls,rs);
	root=merge(merge(k1,k2),k3);
}
inline int xth(int k,int x){
	if(!k)	return 0;
	if(x<=s[s[k].ch[0]].sz)			return xth(s[k].ch[0],x);
	else if(x>s[s[k].ch[0]].sz+1)	return xth(s[k].ch[1],x-s[s[k].ch[0]].sz-1);
	else							return k;
}
inline int pre(int val){
	int r1,r2;
	split(root,val-1,r1,r2);
	int ans=xth(r1,s[r1].sz);
	root=merge(r1,r2);
	return ans;
}
inline int nxt(int val){
	int r1,r2;
	split(root,val,r1,r2);
	int ans=xth(r2,1);
	root=merge(r1,r2);
	return ans;
}
int n=read();
signed main(){
	fz(i,1,n){
		int l=read(),r=read();
		if(i==1){
			insert(l);
			continue;
		}
		int k1=0,k2=0,k3=0;
		int _i=pre(l),_j=nxt(r-1);
//		cout<<_i<<" "<<_j<<endl;
		split(root,l-1,k1,k2);
		split(k2,r-1,k2,k3);
		s[k2].val++;s[k2].lz++;
		root=merge(merge(k1,k2),k3);
		if(_j)	del(s[_j].val);
		insert(l);
//		cout<<s[root].sz<<" "<<s[1].val<<endl;
	}
	cout<<s[root].sz<<endl;
	return 0;
}
/*
5
5 6
2 3
2 3
4 6
9 10
*/