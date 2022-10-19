#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int h,g,n,m,a[N],tp,w,s;
bool f[N];
void find(int x)
{
	if(x>n)
		return;
	if(!f[a[x]]&&a[x]>w&&a[x]<s)
		s=a[x];
	find(x<<1),find(x<<1|1);
}
int pre(int x)
{
	if(x>m)
		return 0;
	w=max(pre(x<<1),pre(x<<1|1));
	s=1e9,find(x);
	f[s]=1;
	return s;
}
int main()
{
	long long ans;
	int T,i;
	scanf("%d",&T),f[0]=1;
	while(T--)
	{
		scanf("%d%d",&h,&g),n=(1<<h)-1,m=(1<<g)-1;
		memset(a,0,n+1<<3);
		for(i=1;i<=n;++i)
			scanf("%d",a+i),f[a[i]]=0;
		pre(1),ans=0;
		for(i=1;i<=n;++i)
			if(f[a[i]])
				ans+=a[i];
		printf("%lld\n",ans);
		for(i=n;i;--i)
			if(!f[a[i]])printf("%d ",i);
		putchar(10); 
	}
	return 0;
}