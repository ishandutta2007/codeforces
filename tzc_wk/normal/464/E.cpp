//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(register int i=a;i<=b;i++)
#define fd(i,a,b)	for(register int i=a;i>=b;i--)
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
//#define int long long
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
const int M=100045;
int n=read(),m=read();
const int HSB1=233,HSB2=2;
const int MOD1=993244853,MOD2=1e9+7;
int P1[110000],P2[110000];
struct edge{
	int u,v,w;
	edge(){/*ycxakioi*/}
	edge(int _u,int _v,int _w){
		u=_u;v=_v;w=_w;
	}
};
vector<edge> g[110000];
struct node{
	int l,r,ch[2],sum,hs1,hs2;
} s[8000006];
int ncnt=0;
int rt[110000];
inline void pushup(int k){
	s[k].sum=s[s[k].ch[0]].sum+s[s[k].ch[1]].sum;
	s[k].hs1=s[s[k].ch[0]].hs1+s[s[k].ch[1]].hs1;
	if(s[k].hs1>=MOD1)	s[k].hs1-=MOD1;
	s[k].hs2=s[s[k].ch[0]].hs2+s[s[k].ch[1]].hs2;
	if(s[k].hs2>=MOD2)	s[k].hs2-=MOD2;
}
inline void build(int &k,int l,int r,int v){
	k=++ncnt;s[k].l=l;s[k].r=r;
	if(l==r){
		s[k].sum=v;
		s[k].hs1=P1[l]*v;
		s[k].hs2=P2[l]*v;
		return;
	}
	int mid=(l+r)>>1;
	build(s[k].ch[0],l,mid,v);
	build(s[k].ch[1],mid+1,r,v);
	pushup(k);
}
inline int query1(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r){
		return s[k].sum;
	}
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid)		return query1(s[k].ch[0],l,r);
	else if(l>mid)	return query1(s[k].ch[1],l,r);
	else			return query1(s[k].ch[0],l,mid)+query1(s[k].ch[1],mid+1,r);
}
inline int find_left(int k,int x){//find leftmost 0 >= x
	if(s[k].l==s[k].r){
		return s[k].l;
	}
	int mid=(s[k].l+s[k].r)>>1;
	if(x>mid)
		return find_left(s[k].ch[1],x);
	else if(query1(k,x,mid)==mid-x+1)
		return find_left(s[k].ch[1],mid+1);
	else
		return find_left(s[k].ch[0],x);
}
inline bool comp(int rt1,int rt2){//rt1>rt2
	if(s[rt1].l==s[rt1].r){
		return s[rt1].sum>=s[rt2].sum;
	}
	int mid=(s[rt1].l+s[rt1].r)>>1;
	if(s[s[rt1].ch[1]].hs1==s[s[rt2].ch[1]].hs1&&s[s[rt1].ch[1]].hs2==s[s[rt2].ch[1]].hs2)
		return comp(s[rt1].ch[0],s[rt2].ch[0]);
	else
		return comp(s[rt1].ch[1],s[rt2].ch[1]);
}
//inline void dfsprint(int k){
//	cout<<s[k].l<<" "<<s[k].r<<" "<<s[k].hs2<<endl;
//	if(s[k].l==s[k].r)	return;
//	dfsprint(s[k].ch[0]);
//	dfsprint(s[k].ch[1]);
//}
inline int modify(int pre,int x){
	int k=++ncnt;s[k]=s[pre];
//	cout<<s[k].l<<" "<<s[k].r<<" "<<s[k].hs2<<" "<<s[s[k].ch[0]].hs2<<endl;
	if(s[k].l==s[k].r){
		s[k].hs1=P1[s[k].l];
		s[k].hs2=P2[s[k].l];
		s[k].sum=1;
		return k;
	}
	int mid=(s[k].l+s[k].r)>>1;
	if(x<=mid)	s[k].ch[0]=modify(s[pre].ch[0],x);
	else		s[k].ch[1]=modify(s[pre].ch[1],x);
	pushup(k);
	return k;
}
inline int connect(int k,int rt,int l,int r){
	if(r<s[rt].l||l>s[rt].r)	return k;
	if(l<=s[rt].l&&s[rt].r<=r){
		return rt;
	}
	int _k=++ncnt;s[_k]=s[k];
	int mid=(s[rt].l+s[rt].r)>>1;
	s[_k].ch[0]=connect(s[k].ch[0],s[rt].ch[0],l,r);
	s[_k].ch[1]=connect(s[k].ch[1],s[rt].ch[1],l,r);
	pushup(_k);
	return _k;
}
inline int add(int _rt,int w){
	int pos=find_left(_rt,w);
	int new_rt=++ncnt;
//	cout<<"w="<<w<<" "<<pos<<endl;
	new_rt=modify(_rt,pos);
//	cout<<s[new_rt].ch[0]<<" "<<s[new_rt].ch[1]<<endl;
	if(pos==w)	return new_rt;
	new_rt=connect(new_rt,rt[0],w,pos-1);
	return new_rt;
}
struct heap{
	int id[110000],id_rt[110000],ch[110000][2],p[110000];
	int root;
	int points,cnt;
	inline int merge(int x,int y){
		if(!x||!y)	return x+y;
		if(comp(id_rt[x],id_rt[y]))	swap(x,y);
		ch[x][1]=merge(ch[x][1],y);
		if(p[ch[x][1]]>p[ch[x][0]])
			swap(ch[x][0],ch[x][1]);
		p[x]=p[ch[x][0]]+1;
		return x;
	}
	inline void push(int x,int y){
		cnt++; 
		id[++points]=x;
		id_rt[points]=y;
		root=merge(root,points);
	}
	inline void pop(){
		root=merge(ch[root][0],ch[root][1]);
		cnt--;
	}
	inline int top(){
		return id[root];
	}
	inline bool empty(){
		return (!cnt);
	}
} q;
int pr[110000];
bool vis[110000];
inline void dijkstra(int from,int to){
	build(rt[n+1],0,M,1);
	fz(i,1,n)	if(i!=from)	rt[i]=rt[n+1];
	build(rt[from],0,M,0);
	rt[0]=rt[from];
	q.push(from,rt[from]);
	while(!q.empty()){
//		if(clock()>4545)	break;
		int x=q.top();q.pop();
		if(vis[x])	continue;
		vis[x]=1;
//		cout<<x<<" "<<s[rt[x]].hs2<<endl;
//		dfsprint(rt[x]);
		for(int i=0;i<g[x].size();i++){
			edge e=g[x][i];
			int y=e.v,z=e.w;
			if(vis[y])	continue;
			int tmp=add(rt[x],z);
//			cout<<x<<" "<<y<<" "<<z<<" "<<s[tmp].hs2<<" "<<comp(rt[y],tmp)<<endl; 
//			cout<<"print tmp\n";
//			dfsprint(tmp);
			if(comp(rt[y],tmp)){
				rt[y]=tmp;
				pr[y]=x;
				q.push(y,rt[y]);
			}
		}
	}
	if(rt[to]==rt[n+1])	puts("-1");
	else{
		cout<<s[rt[to]].hs2<<endl;
		vector<int> ans;
		for(int i=to;i!=from;i=pr[i]){
			ans.push_back(i);
		}
		ans.push_back(from);
		reverse(all(ans));
		cout<<_sz(ans)<<endl;
		foreach(it,ans)	cout<<*it<<" ";
	}
}
signed main(){
	P1[0]=1;
	fz(i,1,M)	P1[i]=1ll*P1[i-1]*HSB1%MOD1;
	P2[0]=1;
	fz(i,1,M)	P2[i]=1ll*P2[i-1]*HSB2%MOD2;
	fz(i,1,m){
		int x=read(),y=read(),z=read();
		g[x].push_back(edge(x,y,z));
		g[y].push_back(edge(y,x,z));
	}
	int _s=read(),_t=read();
	dijkstra(_s,_t);
	return 0;
}