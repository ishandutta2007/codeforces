#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int n,p,m,s[N];
pair<long long,int>a[N];
struct mat{int a[2][2];};
map<long long,int>mp;
long long k;
mat operator*(mat x,mat y)
{
	mat z;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			z.a[i][j]=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				z.a[i][j]=(z.a[i][j]+1ll*x.a[i][k]*y.a[k][j]%p)%p;
	return z;

}
mat tr[N<<2];
mat qp(mat a,long long b)
{
	mat ans=a;
	b--;
	while(b)
	{
		if(b&1)
			ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k].a[0][0]=0;
		tr[k].a[0][1]=s[l-1];
		tr[k].a[1][0]=1;
		tr[k].a[1][1]=s[l];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=tr[k<<1]*tr[k<<1|1];
}
mat query(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	int mid=l+r>>1;
	if(b<=mid) return query(k<<1,l,mid,a,b);
	else if(a>mid) return query(k<<1|1,mid+1,r,a,b);
	else return query(k<<1,l,mid,a,mid)*query(k<<1|1,mid+1,r,mid+1,b);
}
int cal(long long x)
{
	if(mp.find(x)!=mp.end())
		return mp[x];
	return s[x%n];
}
int main()
{
	scanf("%lld%d%lld",&k,&p,&n);
	if(!k)
	{
		puts("0");
		return 0;
	}
	for(int i=0;i<n;i++)
		scanf("%d",&s[i]);
	s[n]=s[0];
	scanf("%d",&m);
	for(int i=0;i<m;i++)
		scanf("%lld%d",&a[i].first,&a[i].second);
	if(mp.find(k)==mp.end())
	{
		a[m]=make_pair(k,0);
		m++;
	}
	build(1,1,n);
	sort(a,a+m);
	for(int i=0;i<m;i++)
		mp[a[i].first]=a[i].second;
	long long l=0;
	int v0=0,v1=1%p;
	for(int i=0;i<m;i++)
	{
		long long x=a[i].first;
		int y=a[i].second;
		x--;
		if(l!=x)
		{
			if(l/n==x/n)
			{
				int n1,n2;
				mat r; 
				r=query(1,1,n,l%n+1,x%n-1+1);
				n1=(1ll*v0*r.a[0][0]+1ll*v1*r.a[1][0])%p,n2=(1ll*v0*r.a[0][1]+1ll*v1*r.a[1][1])%p;
				v0=n1,v1=n2;
			}
			else
			{
				int n1,n2;
				mat r;
				r=query(1,1,n,l%n+1,n);
				n1=(1ll*v0*r.a[0][0]+1ll*v1*r.a[1][0])%p,n2=(1ll*v0*r.a[0][1]+1ll*v1*r.a[1][1])%p;
				v0=n1,v1=n2;
				long long g1=l/n,g2=x/n;
				if(g2-g1-1)
				{
					r=qp(tr[1],g2-g1-1);
					n1=(1ll*v0*r.a[0][0]+1ll*v1*r.a[1][0])%p,n2=(1ll*v0*r.a[0][1]+1ll*v1*r.a[1][1])%p;
					v0=n1,v1=n2;
				}
				if(x%n)
				{
					r=query(1,1,n,1,x%n-1+1);
					n1=(1ll*v0*r.a[0][0]+1ll*v1*r.a[1][0])%p,n2=(1ll*v0*r.a[0][1]+1ll*v1*r.a[1][1])%p;
					v0=n1,v1=n2;
				}
			}
		}
		if(x+1==k)
			break;
		if(i!=m-1&&a[i+1].first==x+2)
		{
			int t=(1ll*cal(x)*v0+1ll*cal(x+1)*v1)%p;
			v0=v1,v1=t;
			l=x+1;
		}
		else
		{
			int t=(1ll*cal(x)*v0+1ll*cal(x+1)*v1)%p;
			v0=v1,v1=t;
			t=(1ll*cal(x+1)*v0+1ll*cal(x+2)*v1)%p;
			v0=v1,v1=t;
			l=x+2;
		}
	}
	printf("%d\n",v1);
	return 0;
}