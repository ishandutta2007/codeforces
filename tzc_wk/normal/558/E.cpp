#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
int n,m;
char ss[100005];
struct SegTree{
	struct node{
		int l,r,val,lz;
	} s[100005<<2];
	inline void build(int k,int l,int r,char x){
		s[k].l=l;s[k].r=r;s[k].lz=-1;
		if(l==r){
			s[k].val=(ss[l]==x);
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid,x);
		build(k<<1|1,mid+1,r,x);
		s[k].val=s[k<<1].val+s[k<<1|1].val;
	}
	inline void pushdown(int k){
		if(s[k].lz!=-1){
			s[k<<1].lz=s[k].lz;
			s[k<<1|1].lz=s[k].lz;
			s[k<<1].val=s[k].lz*(s[k<<1].r-s[k<<1].l+1);
			s[k<<1|1].val=s[k].lz*(s[k<<1|1].r-s[k<<1|1].l+1);
			s[k].lz=-1;
		}
	}
	inline void cover(int k,int l,int r,int x){
		if(l>r)	return;
//		cout<<s[k].l<<" "<<s[k].r<<endl;
		if(l<=s[k].l&&s[k].r<=r){
			s[k].lz=x;
			s[k].val=x*(s[k].r-s[k].l+1);
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		cover(k<<1,l,r,x);
		else if(l>mid)	cover(k<<1|1,l,r,x);
		else			cover(k<<1,l,mid,x),cover(k<<1|1,mid+1,r,x);
		s[k].val=s[k<<1].val+s[k<<1|1].val;
	}
	inline int query(int k,int l,int r){
		if(l>r)	return 0;
//		cout<<s[k].l<<" "<<s[k].r<<endl;
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].val;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query(k<<1,l,r);
		else if(l>mid)	return query(k<<1|1,l,r);
		else			return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
	}
} st[26];
int main(){
	cin>>n>>m>>ss+1;
	fz(i,0,25)	st[i].build(1,1,n,i+'a');
//	puts("a");
	while(m--){
		int l,r,k;cin>>l>>r>>k;
		if(k==1){
			int cur=l;
			fz(i,0,25){
				int num=st[i].query(1,l,r);
				st[i].cover(1,l,r,0);
				st[i].cover(1,cur,cur+num-1,1);
				cur+=num;
			}
		}
		else{
			int cur=l;
			fd(i,25,0){
//				cout<<i<<endl;
				int num=st[i].query(1,l,r);
				st[i].cover(1,l,r,0);
				st[i].cover(1,cur,cur+num-1,1);
				cur+=num;
//				cout<<num<<endl;
			}
		}
	}
	fz(i,1,n)	fz(j,0,25)	if(st[j].query(1,i,i))	putchar(j+'a');
}