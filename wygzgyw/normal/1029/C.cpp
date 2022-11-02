#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=(3e5)+10;
int n,l[maxn],r[maxn],f[maxn];
int d[maxn*2],tot,t2,v[maxn*2];
map<int,int> m;
int cnt[maxn*8],l1[maxn*8];
ll tr[maxn*8],l2[maxn*8];
void pushdown(int root) {
	if (!l1[root]) return;
	cnt[root*2]+=l1[root];
	cnt[root*2+1]+=l1[root];
	l1[root*2]+=l1[root];
	l1[root*2+1]+=l1[root];
	l1[root]=0;
}
void add(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) {
		cnt[root]++; l1[root]++; return;
	}
	pushdown(root);
	int mid=(l+r)/2;
	if (L<=mid) add(L,R,l,mid,root*2);
	if (mid<R) add(L,R,mid+1,r,root*2+1);
	cnt[root]=cnt[root*2]+cnt[root*2+1];
}
int query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return cnt[root];
	pushdown(root);
	int mid=(l+r)/2,res=0;
	if (L<=mid) res+=query(L,R,l,mid,root*2);
	if (mid<R) res+=query(L,R,mid+1,r,root*2+1);
	return res;
}
void pushdown2(int root) {
	if (!l2[root]) return;
	tr[root*2]+=l2[root];
	tr[root*2+1]+=l2[root];
	l2[root*2]+=l2[root];
	l2[root*2+1]+=l2[root];
	l2[root]=0;
}
void add2(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) {
		tr[root]+=delta; l2[root]+=delta; return;
	}
	pushdown2(root);
	int mid=(l+r)/2;
	if (L<=mid) add2(L,R,l,mid,root*2,delta);
	if (mid<R) add2(L,R,mid+1,r,root*2+1,delta);
	tr[root]=tr[root*2]+tr[root*2+1];
}
ll query2(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return tr[root];
	pushdown2(root);
	int mid=(l+r)/2; ll res=0;
	if (L<=mid) res+=query2(L,R,l,mid,root*2);
	if (mid<R) res+=query2(L,R,mid+1,r,root*2+1);
	return res;
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d %d",&l[i],&r[i]);
		d[++tot]=l[i]; d[++tot]=r[i];
	}
	sort(d+1,d+(tot+1));
	for (int i=1;i<=tot;i++)
		if (i==1||d[i]!=d[i-1])
			m[d[i]]=++t2,v[t2]=d[i];
	for (int i=1;i<=n;i++) {
		int x=m[l[i]],y=m[r[i]];
		//printf("%d %d\n",x,y);
		add(x,y,1,t2,1);
		add2(x,y,1,t2,1,i);
	}
	for (int i=1;i<=t2;i++) {
		if (query(i,i,1,t2,1)>=n-1)
			f[i]=(ll)n*(n+1)/2-query2(i,i,1,t2,1);
			//printf(" %d\n",query(i,i,1,t2,1));
		else f[i]=-1;
		//printf("%d ",f[i]);
	}
	//printf("\n");
	int ans=0,lst=-1,now=-1;
	for (int i=1;i<=t2;i++) {
		if (f[i]==-1) lst=now=-1;
		else {
			if (now==0) now=f[i];
			if (f[i]!=now&&f[i]!=0&&now!=-1) {
				while (lst<=i&&f[lst]!=f[i]&&f[lst]!=0) lst++;
				if (lst>i) lst=now=-1; else now=f[i];
			}
			if (lst==-1) lst=i,now=f[i];
			ans=max(ans,v[i]-v[lst]);
		}
	}
	printf("%d\n",ans);
	return 0;
}