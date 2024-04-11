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
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
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
int p[200005],a[200005],n=read();
struct SegTree{
	struct node{
		int l,r,val,mn;
	} s[800005];
	//tot-(up-down);
	inline int query_sum(int k,int l,int r){
		if(l>r)	return 0;
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].val;
		}
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query_sum(k<<1,l,r);
		else if(l>mid)	return query_sum(k<<1|1,l,r);
		else			return query_sum(k<<1,l,mid)+query_sum(k<<1|1,mid+1,r);
	}
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;
		if(l==r){
			s[k].val=s[k].mn=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		s[k].val=s[k<<1].val+s[k<<1|1].val;	
		s[k].mn=max(s[k<<1|1].mn,s[k<<1|1].val+s[k<<1].mn);
	}
	inline void modify(int k,int ind,int x){
		if(s[k].l==s[k].r){
			s[k].val-=x*2;
			s[k].mn=s[k].val;
			return;
		}
		int mid=(s[k].l+s[k].r)>>1;
		if(ind<=mid)	modify(k<<1,ind,x);
		else			modify(k<<1|1,ind,x);
		s[k].val=s[k<<1].val+s[k<<1|1].val;
		s[k].mn=max(s[k<<1|1].mn,s[k<<1|1].val+s[k<<1].mn);
	}
	inline int query(int k,int l,int r){
		if(l>r)	return 0;
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].mn;
		}
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query(k<<1,l,r);
		else if(l>mid)	return query(k<<1|1,l,r);
		else			return max(query(k<<1|1,mid+1,r),query_sum(k<<1|1,mid+1,r)+query(k<<1,l,mid));
	}
} st;
int pos[200005],sum=0;
signed main(){
	fz(i,1,n)	p[i]=read(),pos[p[i]]=i;
	fz(i,1,n)	a[i]=read(),sum+=a[i];
	st.build(1,1,n);
	int ans=0x3f3f3f3f;
	ans=min(ans,sum-st.query(1,2,n));
//	cout<<sum<<" "<<st.query(1,2,n)<<endl;
	fz(i,1,n){
		st.modify(1,pos[i],a[pos[i]]);
		sum-=a[pos[i]];
//		cout<<sum<<" "<<st.query(1,2,n)<<endl;
		ans=min(ans,sum-st.query(1,2,n));
	}
	cout<<ans<<endl;
	return 0;
}