#include <bits/stdc++.h>
using namespace std;
const int maxn=(2e5)+10;
int n,a[maxn],dp[maxn],tr[maxn*4];
void add(int x,int l,int r,int root,int delta) {
	if (l==r) {
		tr[root]=max(tr[root],delta); return;
	}
	int mid=(l+r)/2;
	if (x<=mid) add(x,l,mid,root*2,delta);
	else add(x,mid+1,r,root*2+1,delta);
	tr[root]=max(tr[root*2],tr[root*2+1]);
}
int query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return tr[root];
	int mid=(l+r)/2,res=0;
	if (L<=mid) res=max(res,query(L,R,l,mid,root*2));
	if (mid<R) res=max(res,query(L,R,mid+1,r,root*2+1));
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) {
		int l=0,r=i-1,res=0;
		while (l<=r) {
			int mid=(l+r)/2;
			if (a[mid]*2>=a[i]) res=mid,r=mid-1;
			else l=mid+1;
		}
		if (res) dp[i]=query(res,i-1,1,n,1)+1;
		else dp[i]=1;
		add(i,1,n,1,dp[i]);
	}
	printf("%d\n",query(1,n,1,n,1));
	return 0;
}