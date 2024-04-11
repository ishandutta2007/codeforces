#include<bits/stdc++.h>
using namespace std;
int id[200010],n,last[200010],k,a[200010],cnt,d[200010];
struct node
{
	int x,pos,p;
}m[200010];
bool cmp(node p1,node p2)
{
	return p1.x<p2.x;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i].x);
		m[i].pos=i;
	}
	sort(m+1,m+1+n,cmp);
	m[1].p=1;d[1]=m[1].x;
	for(int i=2;i<=n;i++)
	{
		if(m[i].x==m[i-1].x) m[i].p=m[i-1].p;
		else m[i].p=m[i-1].p+1;
		d[m[i].p]=m[i].x;
	}
	for(int i=1;i<=n;i++) id[m[i].pos]=m[i].p;
	memset(last,0x3f,sizeof(last));
	for(int i=1;i<=n;i++)
	{
		int l=cnt-k+1,r=cnt;
		if(last[id[i]]>=l&&last[id[i]]<=r) continue;
		last[id[i]]=++cnt;
		a[cnt]=id[i];
	}
	int cc=max(cnt-k+1,1);
	printf("%d\n",cnt-cc+1);
	for(int i=cnt;i>=cc;i--) printf("%d ",d[a[i]]);
	printf("\n");
	return 0;
}