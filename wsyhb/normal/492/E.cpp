#include<bits/stdc++.h>
using namespace std;
int x,y;
int exgcd(int a,int b)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b);
	int p=y,q=x-a/b*y;
	x=p,y=q;
	return d;
}
inline int inverse(int v,int mod)
{
	int d=exgcd(v,mod);
	assert(d==1);
	return x+(x<0?mod:0);
}
const int max_n=1e6+5;
int cnt[max_n];
int main()
{
	int n,m,dx,dy;
	scanf("%d%d%d%d",&n,&m,&dx,&dy);
	int inv=inverse(dx,n);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int k=1ll*(n-x)*inv%n;
		++cnt[(y+1ll*k*dy)%n];
	}
	int ans_id=-1,ans_cnt=0;
	for(int i=0;i<n;++i)
	{
		if(cnt[i]>ans_cnt)
		{
			ans_cnt=cnt[i];
			ans_id=i;
		}
	}
	printf("%d %d\n",0,ans_id);
	return 0;
}