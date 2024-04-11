#include<bits/stdc++.h>
using namespace std;
int n;
const int max_n=2e3+50;
int fa[max_n],rk[max_n];
int get_fa(int x)
{
	return fa[x]!=x?fa[x]=get_fa(fa[x]):x;
}
inline void merge(int x,int y)
{
	x=get_fa(x),y=get_fa(y);
	if(x!=y)
	{
		if(rk[x]>rk[y])
			swap(x,y);
		else if(rk[x]==rk[y])
			++rk[y];
		fa[x]=y;
	}
}
int a[max_n];
inline bool check()
{
	for(int i=1;i<=n+30;++i)
		fa[i]=i,rk[i]=0;
	for(int i=1;i<=n;++i)
		for(int j=0;j<30;++j)
		{
			if(a[i]>>j&1)
				merge(i,n+1+j);
		}
	int rt=get_fa(1);
	for(int i=2;i<=n;++i)
	{
		if(get_fa(i)!=rt)
			return false;
	}
	return true;
}
inline void answer(int ans)
{
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)
		printf("%d%c",a[i]," \n"[i==n]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			if(!a[i])
				++a[i],++cnt;
		}
		if(check())
		{
			answer(cnt);
			continue;
		}
		bool flag_over=false;
		for(int i=1;i<=n;++i)
		{
			++a[i];
			if(check())
			{
				answer(cnt+1);
				flag_over=true;
				break;
			}
			a[i]-=2;
			if(check())
			{
				answer(cnt+1);
				flag_over=true;
				break;
			}
			++a[i];
		}
		if(flag_over)
			continue;
		int mx=0;
		for(int i=1;i<=n;++i)
			mx=max(mx,a[i]&(-a[i]));
		assert(mx>1);
		vector<int> pos;
		for(int i=1;i<=n;++i)
		{
			if((a[i]&(-a[i]))==mx)
				pos.push_back(i);
		}
		assert((int)pos.size()>=2);
		++a[pos[0]],--a[pos[1]];
		assert(check());
		answer(cnt+2);
	}
	return 0;
}