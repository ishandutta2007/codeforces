#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
inline int read()
{
	char ch=getchar(); while(!isdigit(ch)) {ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	return ans;
}
inline void print(int x)
{
	if(x<10)
	{
		putchar(x+48);
		return ;
	}
	print(x/10);
	putchar(x%10+48);
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 500005
int B=800;
int n,m,a[N],b[N],fa[N];
int c[N],d[N];
struct Query
{
	int opt,l,r,x,ans;
};
Query q[N];
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
void merge(int x,int y)
{
	if(c[y]) fa[c[x]]=c[y];
	else
	{
		b[c[x]]=y;
		c[y]=c[x];
	}
	d[y]+=d[x];
	c[x]=d[x]=0;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++)
	{
		q[i].opt=read(),q[i].l=read(),q[i].r=read(),q[i].x=read();
	}
	for(int L=1,R=B;L<=n;L+=B,R+=B)
	{
		if(R>n) R=n;
		if(L>n) break;
		int maxn=0,tag=0;
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for(int k=L;k<=R;k++)
		{
			if(a[k]>maxn) maxn=a[k];
			int x=a[k];
			if(c[x]) fa[k]=c[x];
			else
			{
				c[x]=fa[k]=k;
				b[k]=x;
			}
			d[x]++;
		}
		for(int j=1;j<=m;j++)
		{
			int opt=q[j].opt,l=q[j].l,r=q[j].r,x=q[j].x;
			if(r<L||l>R) continue;
			if(opt==1)
			{
				if(l<=L&&R<=r)
				{
					if(x*2<=maxn-tag)
					{
						for(int k=tag+1;k<=tag+x;k++)
						{
							if(c[k]) merge(k,k+x);
						}
						tag+=x;
					}
					else
					{
						for(int k=maxn;k>tag+x;k--)
						{
							if(c[k]) merge(k,k-x);
						}
						maxn=min(maxn,tag+x);
					}
				}
				else
				{
					for(int k=L;k<=R;k++)
					{
						a[k]=b[find(k)];
						c[a[k]]=d[a[k]]=0;
						a[k]-=tag;
					}
					memset(b+L,0,(R-L+1)*4);
					tag=0;
					l=max(l,L),r=min(r,R);
					for(int k=l;k<=r;k++) if(a[k]>x) a[k]-=x;
					maxn=0;
					for(int k=L;k<=R;k++)
					{
						if(a[k]>maxn) maxn=a[k];
						int x=a[k];
						if(c[x]) fa[k]=c[x];
						else
						{
							c[x]=fa[k]=k;
							b[k]=x;
						}
						d[x]++;
					}
				}
			}
			if(opt==2)
			{
				if(l<=L&&R<=r)
				{
					if(x+tag<=500000) q[j].ans+=d[x+tag];
				}
				else
				{
					l=max(l,L),r=min(r,R);
//					for(int k=l;k<=r;k+=4)
//					{
//						if(k==r) q[j].ans+=(b[find(k)]==tag+x);
//						else if(k==r-1) q[j].ans+=(b[find(k-1)]==tag+x)+(b[find(k)]==tag+x);
//						else if(k==r-2) q[j].ans+=(b[find(k-2)]==tag+x)+(b[find(k-1)]==tag+x)+(b[find(k)]==tag+x);
//						else q[j].ans+=(b[find(k-3)]==tag+x)+(b[find(k-2)]==tag+x)+(b[find(k-1)]==tag+x)+(b[find(k)]==tag+x);
//					}
					for(int k=l;k<=r;k++)
					{
						if(b[find(k)]==tag+x) q[j].ans++;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(q[i].opt==2) print(q[i].ans),putchar('\n');
	}
#ifdef __LOCAL__
	cerr<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}

//