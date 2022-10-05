/*
Contest: -
Problem: Codeforces 848C
Author: tzc_wk
Time: 2020.7.17
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
const int INF=1e9;
int n=read(),m=read(),k=0,ans[1000005],a[100005];
struct data{
	int t,p2,p1,p3;
} p[1000005],tmp[1000005];
set<int> st[100005];
struct BIT{
	int bit[2000005];
	inline void add(int x,int v){
		x++;
		for(int i=x;i<=n+1;i+=(i&(-i)))	bit[i]+=v;
	}
	inline int query(int x){
		x++;
		int sum=0;
		for(int i=x;i;i-=(i&(-i)))	sum+=bit[i];
		return sum;
	}
} t;
inline void merge(int l,int r,int mid){
	int p1=l,p2=mid+1;
	for(int i=l;i<=r;i++){
		if(p1<=mid&&(p2>r||p[p1].p2<p[p2].p2))
			tmp[i]=p[p1++];
		else
			tmp[i]=p[p2++];
	}
	for(int i=l;i<=r;i++){
		p[i]=tmp[i];
	}
}
inline void CDQ(int l,int r){
	if(l==r)	return;
	int mid=(l+r)>>1;
	CDQ(l,mid);CDQ(mid+1,r);
//	printf("%d %d\n",l,r);
	int cur=l;
	for(int i=mid+1;i<=r;i++){
		if(p[i].p3!=-INF)	continue;
		while(cur<=mid&&p[cur].p2<=p[i].p2){
			if(p[cur].p3!=-INF)	t.add(p[cur].p1,p[cur].p3);
			cur++;
		}
		ans[p[i].t]+=t.query(n)-t.query(p[i].p1-1);
	}
	fz(i,l,cur-1)	if(p[i].p3!=-INF)	t.add(p[i].p1,-p[i].p3);
	merge(l,r,mid);
}
signed main(){
	fz(i,1,n)	a[i]=read();
	fz(i,1,n)	st[i].insert(0);
	fz(i,1,n){
		p[++k]={k,i,*st[a[i]].rbegin(),i-*st[a[i]].rbegin()};
		st[a[i]].insert(i);
	}
	fz(i,1,n)	st[i].insert(n+1);
	fill1(ans);
	fz(i,1,m){
		int op=read(),x=read(),y=read();
		if(op==1){
			set<int>::iterator pre=--st[a[x]].lower_bound(x);
			set<int>::iterator nxt=st[a[x]].upper_bound(x);
			p[++k]={k,*nxt,x,-((*nxt)-x)};
			p[++k]={k,x,*pre,-(x-(*pre))};
			p[++k]={k,*nxt,*pre,(*nxt)-(*pre)};
			st[a[x]].erase(x);
			a[x]=y;
			pre=--st[a[x]].lower_bound(x);
			nxt=st[a[x]].upper_bound(x);
			p[++k]={k,*nxt,x,((*nxt)-x)};
			p[++k]={k,x,*pre,(x-(*pre))};
			p[++k]={k,*nxt,*pre,-((*nxt)-(*pre))};
			st[a[x]].insert(x);
		}
		else{
			p[++k]={k,y,x,-INF};
			ans[k]=0;
		}
	}
//	fz(i,1,k){
//		printf("%d %d %d %d\n",p[i].t,p[i].p1,p[i].p2,p[i].p3);
//	}
//	puts("-1");
	CDQ(1,k);
	fz(i,1,k)	if(ans[i]!=-1)	printf("%lld\n",ans[i]);
	return 0;
}