#include<bits/stdc++.h>
using namespace std;
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
const int N = 3e5+9;
int n,m,a[N],rt[N];
struct pp{int ch[2],sz;}t[N*64];
int cnt;
int New(){++cnt;ls(cnt)=rs(cnt)=t[cnt].sz=0;return cnt;}
void pushup(int c){t[c].sz=t[ls(c)].sz+t[rs(c)].sz;return ;}
void modify(int &c,int p,int l,int r,int x){
	if(!c) c=New();if(l==r){t[c].sz=t[p].sz+1;return ;}
	int mid=(l+r)>>1;
	if(x<=mid) rs(c)=rs(p),modify(ls(c),ls(p),l,mid,x);
	if(x>mid) ls(c)=ls(p),modify(rs(c),rs(p),mid+1,r,x);
	pushup(c);return ;
}
int query(int c,int p,int l,int r){
	if(!c) return 0;if(l==r) return t[c].sz-t[p].sz;
	int mid=(l+r)>>1;
	if(t[ls(c)].sz-t[ls(p)].sz>t[rs(c)].sz-t[rs(p)].sz) return query(ls(c),ls(p),l,mid);
	return query(rs(c),rs(p),mid+1,r);
}


int main(){
	scanf("%d%d",&n,&m);cnt=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) modify(rt[i],rt[i-1],1,n,a[i]);
	for(int i=1;i<=m;i++){
		int l,r;scanf("%d%d",&l,&r);
		int t=query(rt[r],rt[l-1],1,n);
		int len=r-l+1;
		if(2*t-len<=1) printf("1\n");
		else printf("%d\n",2*t-len);
	}	
	return 0;
}