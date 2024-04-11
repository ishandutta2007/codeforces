#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int ct,n,tmp[Maxn];
struct point
{
	int x,y;
	bool operator < (const point &tmp) const
	{
		if(y!=tmp.y) return y>tmp.y;
		return x<tmp.x;
	}
}P[Maxn];
int sum[Maxn];
int lowbit(int x)
{
	return x&-x;
}
set <int> Se;
void insert(int x,int y)
{
	for(int i=x;i<=n;i+=lowbit(i))
		sum[i]+=1;
}
int ask(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		ans+=sum[i];
	return ans;
}
long long ans;
void work(void)
{
	int cnt=0;
	tmp[ct+1]=n+1;
	for(int i=0;i<=ct;i++)
	{
		cnt=ask(tmp[i+1]-1)-ask(tmp[i]);
		ans-=cnt*(long long)(cnt+1)/2;
	}
	for(int i=1;i<=ct;i++)
		if(Se.find(tmp[i])==Se.end())
			insert(tmp[i],1),Se.insert(tmp[i]);
	cnt=ask(n);
	ans+=cnt*(long long)(cnt+1)/2;
	ct=0;
}
int s[Maxn];
map <int,int> Ma;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&P[i].x,&P[i].y),s[i]=P[i].x;
	sort(P+1,P+1+n);
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++)
		if(s[i]!=s[i-1]) 
			Ma[s[i]]=i;
	for(int i=1;i<=n;i++)
		P[i].x=Ma[P[i].x];
	P[n+1].y=-1;
	P[0]=P[1]; 
	for(int i=1;i<=n+1;i++)
	{
		if(P[i].y!=P[i-1].y)
		{
			work();
			tmp[++ct]=P[i].x;
		}
		else tmp[++ct]=P[i].x;
	}
	printf("%lld",ans);
	return 0;
}