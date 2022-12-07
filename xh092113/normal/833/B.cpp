#include<bits/stdc++.h>
using namespace std;
int n,k;
int i,j,x,l;
int a[35005];
int dp[35005][55];
int last[35005];
int root[35005];
int temp[35005];
struct point
{
	int l;
	int r;
	int maxn;
	int flag;
};
point t[55][140005];
int glc(int x)
{
	return 2 * x;
}
int grc(int x)
{
	return 2 * x + 1;
}
void build(int l,int r,int id,int d)
{
	int m=(l + r) >>1;
	t[id][d].l = l;
	t[id][d].r = r;
	t[id][d].flag = 0;
	if(l == r){t[id][d].maxn = dp[l-1][id-1];return;} 
	build(l,m,id,glc(d));
	build(m+1,r,id,grc(d));
	t[id][d].maxn = max(t[id][glc(d)].maxn , t[id][grc(d)].maxn);
}
void pushdown(int d,int lc,int rc,int id)
{
	int l=t[id][d].l;
	int r=t[id][d].r;
	int m=(l + r) >> 1;
	t[id][lc].flag += t[id][d].flag;
	t[id][rc].flag += t[id][d].flag;
	t[id][lc].maxn += t[id][d].flag;
	t[id][rc].maxn += t[id][d].flag;
	t[id][d].flag = 0;
}
void ud(int l,int r,int x,int id,int d)
{
//cout<<"l,r,x,id,d:"<<l<<" "<<r<<" "<<x<<" "<<id<<" "<<d<<endl;
	int m=(t[id][d].l + t[id][d].r)>>1;
	if(t[id][d].l == l && t[id][d].r == r)
	{
		t[id][d].flag += x;
		t[id][d].maxn += x;
		return;		
	}
	pushdown(d,glc(d),grc(d),id);
	if(r <= m)ud(l,r,x,id,glc(d));
	else if(l >= m+1)ud(l,r,x,id,grc(d));
	else ud(l,m,x,id,glc(d)),ud(m+1,r,x,id,grc(d));
	t[id][d].maxn = max(t[id][glc(d)].maxn , t[id][grc(d)].maxn);
}
int query(int l,int r,int id,int d)
{
	int m=(t[id][d].l + t[id][d].r)>>1;
	if(t[id][d].l == l && t[id][d].r == r)return t[id][d].maxn;
	pushdown(d,glc(d),grc(d),id);
	if(r <= m)return query(l,r,id,glc(d));
	if(l >= m+1)return query(l,r,id,grc(d));
	return max(query(l,m,id,glc(d)),query(m+1,r,id,grc(d)));	
}
int main()
{
	//freopen("834D.in","r",stdin);
	//freopen("834D.out","w",stdout);
	scanf("%d%d",&n,&k);
	memset(last,0,sizeof(last));
	memset(temp,0,sizeof(temp));
//cout<<n<<" "<<k<<endl;
	for(i=1;i<=n;i++)
	{
//cout<<i<<endl;
		scanf("%d",&a[i]);
		last[i]=temp[a[i]];
		temp[a[i]]=i;
	}
//cout<<"last[]:";for(i=1;i<=n;i++)cout<<last[i]<<" ";cout<<endl;
	for(i=0;i<=k-1;i++)
		for(j=i+1;j<=k;j++)dp[i][j]=-2147483647;
	for(i=0;i<=n;i++)dp[i][0]=0;
	for(x=1;x<=k;x++)dp[x][x]=x;
//cout<<1<<endl;
	for(x=1;x<=k;x++)
	{	
		build(1,n,x,1);
//cout<<"build up"<<endl;
		for(i=x;i<=n;i++)
		{
//cout<<"x="<<x<<" i="<<i<<endl;
			ud(last[i]+1,i,1,x,1);
//for(l=1;l<=i;l++)cout<<query(l,l,x,1)<<" ";cout<<endl;
//cout<<"maxn="<<query(x,i,x,1)<<endl;
			dp[i][x]=query(x,i,x,1);
		}
	} 
	printf("%d\n",dp[n][k]);
	//fclose(stdin);
	//fclose(stdout);
	return 0;	
}