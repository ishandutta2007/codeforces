#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(4e6)+10;
const int INF=(1e9);
int n,mx[maxn],mn[maxn];
char s[maxn],t[maxn];
int lazy[maxn];
void pushdown(int root) {
	if (!lazy[root]) return;
	mx[root*2]+=lazy[root];
	mn[root*2]+=lazy[root];
	lazy[root*2]+=lazy[root];
	mx[root*2+1]+=lazy[root];
	mn[root*2+1]+=lazy[root];
	lazy[root*2+1]+=lazy[root];
	lazy[root]=0;
}
void add(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) {
		lazy[root]+=delta;
		mx[root]+=delta;
		mn[root]+=delta;
		return;
	}
	pushdown(root);
	int mid=(l+r)/2;
	if (L<=mid) add(L,R,l,mid,root*2,delta);
	if (mid<R) add(L,R,mid+1,r,root*2+1,delta);
	mx[root]=max(mx[root*2],mx[root*2+1]);
	mn[root]=min(mn[root*2],mn[root*2+1]);
}
int query(int L,int R,int l,int r,int root,int op) {
	if (L<=l&&r<=R) {
		if (!op) return mn[root];
		return mx[root];
	}
	pushdown(root);
	int mid=(l+r)/2,res;
	if (!op) res=INF; else res=-INF;
	if (L<=mid) {
		if (!op) res=min(res,query(L,R,l,mid,root*2,op));
		else res=max(res,query(L,R,l,mid,root*2,op));
	}
	if (mid<R) {
		if (!op) res=min(res,query(L,R,mid+1,r,root*2+1,op));
		else res=max(res,query(L,R,mid+1,r,root*2+1,op));
	}
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); scanf("%s",s+1);
	n=strlen(s+1);
	int pos=1,delta,mx=0;
	for (int i=1;i<=n;i++) {
		if (s[i]=='L') {
			if (pos>1) pos--;
		} else if (s[i]=='R') pos++;
		else {
			if (s[i]=='(') delta=1;
			else if (s[i]==')') delta=-1;
			else delta=0;
			if (t[pos]=='(') delta--;
			else if (t[pos]==')') delta++;
			t[pos]=s[i];
		//	printf("A %d %d\n",pos,delta);
			if (delta) add(pos,n,1,n,1,delta);
		}
	//	printf("%s\n",t+1);
		if (query(1,n,1,n,1,0)<0||query(n,n,1,n,1,0)!=0) printf("-1 ");
		else printf("%d ",query(1,n,1,n,1,1));
	} printf("\n");
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/