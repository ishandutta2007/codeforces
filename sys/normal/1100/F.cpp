#include <bits/stdc++.h>
using namespace std;
const int Maxn=500005;
int bas[21],pos[21],n,rt,a[Maxn],q;
struct quest
{
	int lt,rt,id;
	bool operator < (const quest &tmp) const
	{
		return rt<tmp.rt;
	}
}Q[Maxn];
void insert(int x,int id)
{
	for(int i=20;i>=0;i--)
	{
		if(x&(1<<i))
		{
			if(!bas[i])
			{
				bas[i]=x;
				pos[i]=id;
				return ;
			}
			if(pos[i]<id) swap(pos[i],id),swap(x,bas[i]);
			x^=bas[i];
		}
	}
}
int work(int lt)
{
	int ans=0;
	for(int i=20;i>=0;i--)
		if(pos[i]>=lt&&ans<(ans^bas[i]))
			ans^=bas[i];
	return ans;
}
int ans[Maxn];
int main()
{ 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
		scanf("%d%d",&Q[i].lt,&Q[i].rt),Q[i].id=i;
	sort(Q+1,Q+1+q);
	for(int i=1;i<=q;i++)
	{
		while(rt<Q[i].rt)
		{
			rt++;
			insert(a[rt],rt);
		}
		ans[Q[i].id]=work(Q[i].lt);
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}