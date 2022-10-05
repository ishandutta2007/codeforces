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
int n=read(),a[200005],key[200005],hs[200005],cnt=0;
struct node{
	int ch[2],l,r,val;
} s[200005<<5];
int ncnt=0,rt[200005];
inline void build(int &k,int l,int r){
	k=++ncnt;s[k].l=l;s[k].r=r;
	if(l==r)	return;
	int mid=(s[k].l+s[k].r)>>1;
	build(s[k].ch[0],l,mid);
	build(s[k].ch[1],mid+1,r);
}
inline void modify(int &k,int pre,int ind){
	k=++ncnt;s[k]=s[pre];s[k].val++;
	if(s[k].l==s[k].r)	return;
	int mid=(s[k].l+s[k].r)>>1;
	if(ind<=mid)	modify(s[k].ch[0],s[pre].ch[0],ind);
	else			modify(s[k].ch[1],s[pre].ch[1],ind);
	s[k].val=s[s[k].ch[0]].val+s[s[k].ch[1]].val;
}
inline int query(int k,int l,int r){
//	cout<<k<<" "<<l<<" "<<r<<" "<<s[k].l<<" "<<s[k].r<<endl;
	if(l>r)	return 0;
	if(l<=s[k].l&&s[k].r<=r){
		return s[k].val;
	}
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid)		return query(s[k].ch[0],l,r);
	else if(l>mid)	return query(s[k].ch[1],l,r);
	else			return query(s[k].ch[0],l,mid)+query(s[k].ch[1],mid+1,r);
}
signed main(){
	fz(i,1,n)	a[i]=read(),key[i]=a[i];
	sort(key+1,key+n+1);
	key[0]=-0x3f3f3f3f;
	fz(i,1,n)	if(key[i]!=key[i-1])	hs[++cnt]=key[i];
	fz(i,1,n)	a[i]=lower_bound(hs+1,hs+cnt+1,a[i])-hs;
	build(rt[0],1,cnt);
	fz(i,1,n)	modify(rt[i],rt[i-1],a[i]);
//	puts("-1");
	fz(k,1,n-1){
		int ans=0;
		for(int j=1;j<=n&&(j*k-k+2)<=n;j++){
//			cout<<j<<endl;
//			cout<<j*k-k+2<<" "<<min(j*k+1,n)<<" "<<a[j]-1<<" "<<query(rt[min(j*k+1,n)],1,a[j]-1)<<" "<<query(rt[(j*k-k+2)],1,a[j]-1)<<endl;
			ans+=query(rt[min(j*k+1,n)],1,a[j]-1)-query(rt[(j*k-k+2)-1],1,a[j]-1);
		}
		cout<<ans<<" ";
	}
	return 0;
}