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
	int ch[2],l,r,mx;
} s[300005<<5];
int cnt=0,rt[300005];
inline void build(int &k,int l,int r){
	k=++cnt;s[k].l=l;s[k].r=r;
	s[k].mx=0x3f3f3f3f;
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	build(s[k].ch[0],l,mid);
	build(s[k].ch[1],mid+1,r);
}
inline void modify(int &k,int pre,int x,int y){
	k=++cnt;s[k]=s[pre];
	if(s[k].l==s[k].r){
		s[k].mx=min(s[k].mx,y);
		return;
	}
	int mid=(s[k].l+s[k].r)>>1;
	if(x<=mid)	modify(s[k].ch[0],s[pre].ch[0],x,y);
	else		modify(s[k].ch[1],s[pre].ch[1],x,y);
	s[k].mx=max(s[s[k].ch[0]].mx,s[s[k].ch[1]].mx);
}
inline int query(int k,int l,int r){
//	cout<<"k="<<k<<endl;
	if(l<=s[k].l&&s[k].r<=r){
		return s[k].mx;
	}
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid)		return query(s[k].ch[0],l,r);
	else if(l>mid)	return query(s[k].ch[1],l,r);
	else			return max(query(s[k].ch[0],l,mid),query(s[k].ch[1],mid+1,r));
}
int n=read(),m=read(),k=read();
int l[300005],r[300005],p[300005],key[300005],cntt=0,hs[300005],cnt2=0;
inline int get(int x){
	return lower_bound(hs+1,hs+cnt2+1,x)-hs;
}
int ed[300005];
vector<int> ls[300005];
signed main(){
	fz(i,1,k){
		l[i]=read();
		r[i]=read();
		p[i]=read();
		key[++cntt]=l[i];
	}
	sort(key+1,key+cntt+1);
	fz(i,1,cntt)	if(key[i]!=key[i-1])	hs[++cnt2]=key[i];
	fz(i,1,k)		ls[get(l[i])].push_back(i);
	build(rt[k+1],1,n);
	int cur=k+1;ed[cnt2+1]=k+1;
	fd(i,cnt2,1){
		foreach(it,ls[i]){
			int ind=*it;
			cur--;
			modify(rt[cur],rt[cur+1],p[ind],r[ind]);
		}
		ed[i]=cur;
	}
	while(m--){
		int l=read(),r=read(),x=read(),y=read();
		x=get(x);
//		cout<<x<<endl;
//		cout<<ed[x]<<endl;
		if(query(rt[ed[x]],l,r)<=y)	puts("yes"),fflush(stdout);
		else						puts("no"),fflush(stdout);
	}
	return 0;
}