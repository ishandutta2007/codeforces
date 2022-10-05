/*
Contest: Codeforces Round #668 (Div.1)
Problem: Codeforces 1404C
Author: tzc_wk
Time: 2020.9.6
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),q=read();
struct node{
	int l,r,val,which,lz;
} s[300005<<2];
inline void pushup(int k){
	s[k].val=0x3f3f3f3f;
	if(s[k<<1|1].val<s[k].val) s[k].val=s[k<<1|1].val,s[k].which=s[k<<1|1].which;
	if(s[k<<1].val<s[k].val) s[k].val=s[k<<1].val,s[k].which=s[k<<1].which;
}
inline void pushdown(int k){
	if(s[k].lz){
		s[k<<1].val+=s[k].lz;s[k<<1].lz+=s[k].lz;
		s[k<<1|1].val+=s[k].lz;s[k<<1|1].lz+=s[k].lz;
		s[k].lz=0;
	}
}
inline void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].val=0x3f3f3f3f;s[k].which=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
inline void modify(int k,int ind,int x){
	if(s[k].l==s[k].r){
		s[k].val=x;return;
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(ind<=mid) modify(k<<1,ind,x);
	else modify(k<<1|1,ind,x);
	pushup(k);
}
inline void change(int k,int l,int r,int x){
	if(l>r) return;
	if(l<=s[k].l&&s[k].r<=r){
		s[k].val+=x;s[k].lz+=x;return;
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) change(k<<1,l,r,x);
	else if(l>mid) change(k<<1|1,l,r,x);
	else change(k<<1,l,mid,x),change(k<<1|1,mid+1,r,x);
	pushup(k);
}
int a[300005],pth[300005],pth_cnt=0;
struct query{
	int x,y,id;
	friend bool operator <(query a,query b){
		return a.x<b.x;
	}
} qr[300005];
int bit[300005];
inline void add(int x,int v){
	for(int i=x;i<=n;i+=(i&(-i))) bit[i]+=v;
}
inline int query(int x){
	int sum=0;for(int i=x;i;i-=(i&(-i))) sum+=bit[i];return sum;
}
int pos[300005],ans[300005];
int main(){
	build(1,1,n);
	fz(i,1,n) a[i]=read();
	fz(i,1,n) if(a[i]<=i) modify(1,i,i-a[i]);
	while(s[1].val==0){
		int x=s[1].which;
		pth[++pth_cnt]=x;modify(1,x,0x3f3f3f3f);change(1,x+1,n,-1);
	}
	fz(i,1,pth_cnt) pos[pth[i]]=i,add(pth[i],1);
	fz(i,1,q) qr[i].x=read(),qr[i].y=read(),qr[i].id=i;
	sort(qr+1,qr+q+1);
	int cur=1,mn=pth_cnt;
	fz(i,1,q){
//		cout<<i<<endl;
		while(cur<=qr[i].x){
			if(pos[cur]){
				int nmn=min(pos[cur]-1,mn);
				fz(j,nmn+1,mn) add(pth[j],-1);
				mn=nmn;
			}
			cur++;
		}
		ans[qr[i].id]=query(n-qr[i].y);
	}
//	cout<<pth_cnt<<endl;
	fz(i,1,q) cout<<ans[i]<<endl;
	return 0;
}