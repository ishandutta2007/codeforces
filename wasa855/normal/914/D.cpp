#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 500005
int lson(int u){return u<<1;}
int rson(int u){return u<<1|1;}
int gcd(int x,int y){return __gcd(x,y);}
int a[N];
int val[N*4];
bool ok;
int cnt;
void build(int u,int l,int r)
{
	if(l==r)
	{
		val[u]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(lson(u),l,mid);
	build(rson(u),mid+1,r);
	val[u]=gcd(val[lson(u)],val[rson(u)]);
}
void update(int u,int l,int r,int p,int dat)
{
	if(l==r)
	{
		val[u]=dat;
		return ;
	}
	int mid=(l+r)>>1;
	if(p<=mid) update(lson(u),l,mid,p,dat);
	else update(rson(u),mid+1,r,p,dat);
	val[u]=gcd(val[lson(u)],val[rson(u)]);
}
void query(int u,int l,int r,int L,int R,int g)
{
	if(cnt>1) return ;
	if(l==r)
	{
		if(val[u]%g) cnt++;
		return ;
	}
	if(val[u]%g==0) return ;
	int mid=(l+r)>>1;
	if(mid>=L) query(lson(u),l,mid,L,R,g);
	if(mid<R)query(rson(u),mid+1,r,L,R,g);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	cin>>m;
	int opt,u,v,w;
	for(int i=1;i<=m;i++)
	{
		opt=read();
		if(opt==1)
		{
			u=read(),v=read(),w=read();
			cnt=0;
			query(1,1,n,u,v,w);
//			cout<<cnt<<endl;
			if(cnt>1) printf("NO\n");
			else printf("YES\n"); 
		}
		else
		{
			u=read(),v=read();
			update(1,1,n,u,v);
		}
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}