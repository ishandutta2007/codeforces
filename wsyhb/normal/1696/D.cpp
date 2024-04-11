#include<bits/stdc++.h>
using namespace std;
int n;
const int max_n=2.5e5+5;
int a[max_n],pos[max_n];
struct ST_table
{
	int type;
	inline ST_table(int Type)
	{
		type=Type;
	}
	inline int calc(int x,int y)
	{
		return type?max(x,y):min(x,y);
	}
	int Log[max_n],f[18][max_n];
	inline void init()
	{
		Log[0]=-1;
		for(int i=1;i<=n;++i)
		{
			Log[i]=Log[i>>1]+1;
			f[0][i]=a[i];
		}
		for(int i=1;i<=Log[n];++i)
			for(int j=1;j+(1<<i)-1<=n;++j)
				f[i][j]=calc(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	}
	inline int query(int l,int r)
	{
		assert(l<=r);
		int k=Log[r-l+1];
		return calc(f[k][l],f[k][r-(1<<k)+1]);
	}
}mn(0),mx(1);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			pos[a[i]]=i;
		}
		mn.init(),mx.init();
		int now=1,ans=0;
		while(now<n)
		{
			++ans;
			int L=now+1,R=n,res=now;
			if(a[now]<a[now+1])
			{
				while(L<=R)
				{
					int mid=(L+R)>>1;
					if(mn.query(now,mid)==a[now])
						res=mid,L=mid+1;
					else
						R=mid-1;
				}
				now=pos[mx.query(now,res)];
			}
			else
			{
				while(L<=R)
				{
					int mid=(L+R)>>1;
					if(mx.query(now,mid)==a[now])
						res=mid,L=mid+1;
					else
						R=mid-1;
				}
				now=pos[mn.query(now,res)];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}