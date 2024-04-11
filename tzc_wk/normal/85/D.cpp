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
struct node{
	int ind,sz,val,sum[5],ch[2],add_lz,key;
} s[100005];
int ncnt=0,root=0;
inline void pushup(int k){
	if(!k)	return;
	s[k].sz=s[s[k].ch[0]].sz+s[s[k].ch[1]].sz+1;
	fz(i,0,4){
		s[k].sum[i]=s[s[k].ch[0]].sum[i];
	}	
	s[k].sum[s[s[k].ch[0]].sz%5]+=s[k].val;
	fz(i,0,4){
		s[k].sum[(i+s[s[k].ch[0]].sz+1)%5]+=s[s[k].ch[1]].sum[i];
	}
}
inline void split(int k,int val,int &a,int &b){
	pushup(k);
	if(!k){
		a=b=0;
		return;
	}
	if(val<s[k].val){
		b=k;split(s[k].ch[0],val,a,s[k].ch[0]);
	}
	else{
		a=k;split(s[k].ch[1],val,s[k].ch[1],b);
	}
	pushup(a);
	pushup(b);
}
inline int merge(int a,int b){
	if(!a||!b)	return a+b;
	pushup(a);pushup(b);
	if(s[a].key<s[b].key){
		s[a].ch[1]=merge(s[a].ch[1],b);
		pushup(a);return a;
	}
	else{
		s[b].ch[0]=merge(a,s[b].ch[0]);
		pushup(b);return b;
	}
}
inline int newnode(int val,int ind){
	s[++ncnt].val=val;
	s[ncnt].key=rand()<<15|rand();
	s[ncnt].sum[ind%5]=val;
	s[ncnt].sz=1;
	return ncnt;
}
inline void insert(int val){
	int k1,k2;
	split(root,val,k1,k2);
	root=merge(merge(k1,newnode(val,s[k1].sz)),k2);
//	cout<<k1<<" "<<k2<<" "<<root<<" "<<s[root].sum[1]<<endl;
}
inline void del(int val){
	int k1,k2,k3;
	split(root,val-1,k1,k2);
	split(k2,val,k2,k3);
	root=merge(k1,k3);
}
signed main(){
	int T=read();
	while(T--){
		char opt[5];cin>>opt+1;
		if(opt[1]=='a'){
			int x=read();
			insert(x); 
		}
		if(opt[1]=='d'){
			int x=read();del(x);
		}
		if(opt[1]=='s'){
			cout<<s[root].sum[2]<<endl;
		}
	}
	return 0;
}