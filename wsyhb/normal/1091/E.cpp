#include<bits/stdc++.h>
using namespace std;
int n;
const int max_n=5e5+5;
int a[max_n],d[max_n],cnt[max_n];
inline int check(int x)
{
	assert(x>=0&&x<=n);
	for(int i=0;i<=n;++i)
		cnt[i]=0;
	for(int i=1;i<=n;++i)
	{
		d[i]=a[i];
		++cnt[a[i]];
	}
	d[n+1]=x;
	++cnt[x];
	int pos=n+1;
	while(pos>1&&d[pos]>d[pos-1])
		swap(d[pos],d[pos-1]),--pos;
//	for(int i=1;i<=n+1;++i)
//		fprintf(stderr,"i=%d d[i]=%d\n",i,d[i]);
	long long sum_left=0,sum_k=0;
	int cnt_k=cnt[0];
	for(int k=1;k<=n+1;++k)
	{
		sum_left+=d[k];
		sum_k+=1ll*cnt[k]*k;
		cnt_k+=cnt[k];
		if(d[k]<=k)
			sum_k-=d[k],--cnt_k;
		else
			--cnt[d[k]];
		if(sum_left>k*(k-1ll)+sum_k+(n+1ll-k-cnt_k)*k)
			return pos<=k?-1:1;
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1,greater<int>());
	int l=0,r=n,res=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int ret=check(mid);
		if(!ret)
		{
			res=mid;
			break;
		}
		if(ret==1)
			l=mid+1;
		else
			r=mid-1;
	}
//	fprintf(stderr,"res=%d\n",res);
	if(!~res)
	{
		puts("-1");
		return 0;
	}
	int ansL=res,ansR=res;
	l=0,r=res-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(!check(mid))
			ansL=mid,r=mid-1;
		else
			l=mid+1;
	}
	l=res+1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(!check(mid))
			ansR=mid,l=mid+1;
		else
			r=mid-1;
	}
	int par=0;
	for(int i=1;i<=n;++i)
		par^=a[i];
	par&=1;
	if(ansR>ansL||(ansL&1)==par)
	{
		for(int i=ansL+((ansL&1)^par);i<=ansR;i+=2)
			printf("%d%c",i,i+2<=ansR?' ':'\n');
	}
	else
		puts("-1");
	return 0;
}