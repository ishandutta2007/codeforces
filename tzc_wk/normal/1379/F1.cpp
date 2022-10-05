/*
Contest: -
Problem: Codeforces 1379F2
Author: tzc_wk
Time: 2020.7.26
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),m=read(),q=read();
struct tree2d{
	struct node{
		int ch[2],val;
		node(){ch[0]=ch[1]=val=0;}
	} s[20000005];
	int rt[200005],cnt=0;
	inline int newnode(int val){
		s[++cnt].val=val;
		return cnt;
	}
	tree2d(){
		for(int i=1;i<=n;i++) rt[i]=newnode(0);
	}
	inline void update_in(int &k,int l,int r,int ind,int v){
//		printf("%d %d %d %d %d\n",k,l,r,ind,v);
		if(l==r){
			s[k].val+=v;
			return;
		}
		int mid=(l+r)>>1;
		if(ind<=mid){
			if(!s[k].ch[0]) s[k].ch[0]=newnode(0);
			update_in(s[k].ch[0],l,mid,ind,v);
		}
		else{
			if(!s[k].ch[1]) s[k].ch[1]=newnode(0);
			update_in(s[k].ch[1],mid+1,r,ind,v);
		}
		s[k].val=s[s[k].ch[0]].val+s[s[k].ch[1]].val;
	}
	inline int query_in(int &k,int cl,int cr,int l,int r){
		if(!k) return 0;
		if(l<=cl&&cr<=r) return s[k].val;
		int mid=(cl+cr)>>1;
		if(r<=mid) return query_in(s[k].ch[0],cl,mid,l,r);
		else if(l>mid) return query_in(s[k].ch[1],mid+1,cr,l,r);
		else return query_in(s[k].ch[0],cl,mid,l,mid)+query_in(s[k].ch[1],mid+1,cr,mid+1,r);
	}
	inline void add_out(int x,int y,int v){
		for(int i=x;i<=n;i+=(i&(-i))) update_in(rt[i],1,m,y,v);
	}
	inline int query_out(int p,int x,int y){
		int sum=0;
		for(int i=p;i;i-=i&(-i)) sum+=query_in(rt[i],1,m,x,y);
		return sum;
	}
	inline int query(int p,int q,int x,int y){
		return query_out(q,x,y)-query_out(p-1,x,y);
	}
} t[2];
int pairs=0;
set<pii> st;
signed main(){
	while(q--){
		int x=read(),y=read();
		int px=(x+1)/2,py=(y+1)/2;
//		printf("%d %d\n",px,py);
		if(!st.count(pii(x,y))){
			if(x%2){
				t[0].add_out(px,py,1);
				pairs+=t[1].query(px,n,py,m);
			}
			else{
				t[1].add_out(px,py,1);
				pairs+=t[0].query(1,px,1,py);
//				printf("%d\n",t[0].query(1,px,1,py));
			}
			st.insert(pii(x,y));
		}
		else{
			if(x%2){
				t[0].add_out(px,py,-1);
				pairs-=t[1].query(px,n,py,m);
			}
			else{
				t[1].add_out(px,py,-1);
				pairs-=t[0].query(1,px,1,py);
			}
			st.erase(pii(x,y));
		}
		printf("%s\n",(pairs==0)?("YES"):("NO"));
	}
	return 0;
}