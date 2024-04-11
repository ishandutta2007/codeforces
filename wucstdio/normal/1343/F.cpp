#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Array
{
	int size;
	bool flag[205];
	void del(int x)
	{
		if(flag[x])size--;
		flag[x]=0;
	}
	void print()
	{
		printf("size=%d\n",size);
		for(int i=1;i<=200;i++)
		  if(flag[i])printf("%d ",i);
		printf("\n");
	}
};
Array a[205],b[205];
int t,n,res[205],pos[205],tmp[205];
bool cmp(Array a,Array b)
{
	return a.size<b.size;
}
bool check()
{
	for(int i=1;i<=n;i++)pos[res[i]]=i;
	for(int i=1;i<n;i++)
	{
		int minn=n,maxx=1;
		for(int j=1;j<=n;j++)
		{
			if(b[i].flag[j])
			{
				minn=min(minn,pos[j]);
				maxx=max(maxx,pos[j]);
			}
		}
		if(maxx-minn+1!=b[i].size)return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			scanf("%d",&a[i].size);
			for(int j=1;j<=n;j++)a[i].flag[j]=0;
			for(int j=1;j<=a[i].size;j++)
			{
				int x;
				scanf("%d",&x);
				a[i].flag[x]=1;
			}
		}
		sort(a+1,a+n,cmp);
		for(int i=1;i<n;i++)
		{
			b[i].size=a[i].size;
			for(int j=1;j<=n;j++)b[i].flag[j]=a[i].flag[j];
		}
		for(int x=1;b[x].size==2;x++)
		{
			for(int i=1;i<n;i++)
			{
				a[i].size=b[i].size;
				for(int j=1;j<=n;j++)a[i].flag[j]=b[i].flag[j];
//				a[i].print();
			}
			int u=0,v=0;
			while(!b[x].flag[u])u++;
			b[x].flag[u]=0;
			while(!b[x].flag[v])v++;
			b[x].flag[v]=0;
			b[x].flag[u]=b[x].flag[v]=1;
			int cntu=0,cntv=0;
			for(int i=1;i<n;i++)
			{
				if(a[i].flag[u])cntu++;
				if(a[i].flag[v])cntv++;
			}
			if(cntu>cntv)swap(u,v);
//			printf("test %d %d\n",u,v);
			for(int i=1;i<n;i++)
				a[i].del(u),a[i].del(v);
			res[1]=u,res[2]=v;
			bool flag=1;
			for(int i=3;i<=n;i++)
			{
//				printf("i=%d\n",i);
				int num=0,last=0;
				for(int j=1;j<n;j++)
				{
//					a[j].print();
					if(a[j].size==1)num++,last=j;
				}
				if(num!=1)
				{
					flag=0;
					break;
				}
				res[i]=1;
				while(!a[last].flag[res[i]])res[i]++;
				for(int j=1;j<n;j++)a[j].del(res[i]);
			}
			flag&=check();
			if(flag)
			{
				for(int i=1;i<=n;i++)printf("%d ",res[i]);
				printf("\n");
				break;
			}
		}
	}
	return 0;
}