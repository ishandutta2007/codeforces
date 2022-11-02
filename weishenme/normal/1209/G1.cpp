#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int ne[N],tot,fi[N],q,zz[N],x,l[N],r[N],y,n,m,a[N],b[N],c[N];
char s[N];
struct Ask{
	int l,r,cnt;
}A[N];
int cmp(Ask x,Ask y){
	return x.l<y.l;
}
signed main(){
	scanf("%d%d",&n,&q);
	m=2e5;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)l[i]=1e9;
	for (int i=1;i<=n;i++)l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i),b[a[i]]++;
	n=0;
	for (int i=1;i<=m;i++)
		if (l[i]<=r[i])A[++n].l=l[i],A[n].r=r[i],A[n].cnt=b[i];
	sort(A+1,A+n+1,cmp);
	Ask now=A[1];int ans=0;
	for (int i=2;i<=n;i++)
		if (A[i].l>now.r)now=A[i];
		else {
			now.r=max(now.r,A[i].r);
			ans+=min(now.cnt,A[i].cnt);
			now.cnt=max(A[i].cnt,now.cnt);
		}
	printf("%d\n",ans);	
}