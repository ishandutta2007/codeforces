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
int n=read(),A=read(),d[300005],c[300005],dif[300005],l[300005],r[300005];
struct SegTree{
	struct node{
		int l,r,sum,lmx,rmx,mx;
	} s[300005<<2];
	inline void pushup(int k){
		s[k].lmx=max(s[k<<1].lmx,s[k<<1].sum+s[k<<1|1].lmx);
		s[k].rmx=max(s[k<<1|1].rmx,s[k<<1|1].sum+s[k<<1].rmx);
		s[k].sum=s[k<<1].sum+s[k<<1|1].sum;
		s[k].mx=max(max(s[k<<1].mx,s[k<<1|1].mx),s[k<<1].rmx+s[k<<1|1].lmx);
	}
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;
		if(l==r){
			s[k].sum=A-c[l];
			s[k].lmx=s[k].rmx=s[k].mx=max(0ll,s[k].sum);
			return;
		}
		int mid=(s[k].l+s[k].r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		pushup(k);
	}
	inline int query_sum(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].sum;
		}
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query_sum(k<<1,l,r);
		else if(l>mid)	return query_sum(k<<1|1,l,r);
		else			return query_sum(k<<1,l,mid)+query_sum(k<<1|1,mid+1,r);
	}
	inline int query_lmx(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].lmx;
		}
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query_lmx(k<<1,l,r);
		else if(l>mid)	return query_lmx(k<<1|1,l,r);
		else			return max(query_lmx(k<<1,l,mid),query_sum(k<<1,l,mid)+query_lmx(k<<1|1,mid+1,r));
	}
	inline int query_rmx(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].rmx;
		}
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query_rmx(k<<1,l,r);
		else if(l>mid)	return query_rmx(k<<1|1,l,r);
		else			return max(query_rmx(k<<1|1,mid+1,r),query_sum(k<<1|1,mid+1,r)+query_rmx(k<<1,l,mid));
	}
	inline int query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].mx;
		}
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query(k<<1,l,r);
		else if(l>mid)	return query(k<<1|1,l,r);
		else			return max(max(query(k<<1,l,mid),query(k<<1|1,mid+1,r)),query_rmx(k<<1,l,mid)+query_lmx(k<<1|1,mid+1,r));
	}
} st;
signed main(){
	fz(i,1,n)	d[i]=read(),c[i]=read();
	fz(i,1,n-1)	dif[i]=d[i+1]-d[i];
	stack<pii> stk;
	fz(i,1,n-1){
		if(i==1){
			stk.push({dif[i],i});
			l[i]=1;
			continue;
		}
		while(!stk.empty()&&stk.top().fi<=dif[i])	stk.pop();
		if(stk.empty())	l[i]=1;
		else			l[i]=stk.top().se+1;
		stk.push({dif[i],i});
	}
	while(!stk.empty())	stk.pop();
	fd(i,n-1,1){
		if(i==n-1){
			stk.push({dif[i],i});
			r[i]=n;
			continue;
		}
		while(!stk.empty()&&stk.top().fi<=dif[i])	stk.pop();
		if(stk.empty())	r[i]=n;
		else			r[i]=stk.top().se;
		stk.push({dif[i],i});
	}
	st.build(1,1,n);
	int ans=0;
	fz(i,1,n)	ans=max(ans,A-c[i]);
	fz(i,1,n-1){
//		cout<<l[i]<<" "<<r[i]<<endl;
//		cout<<st.query(1,l[i],r[i])<<endl;
		ans=max(ans,st.query(1,l[i],r[i])-dif[i]*dif[i]);
	}
	cout<<ans<<endl;
	return 0;
}