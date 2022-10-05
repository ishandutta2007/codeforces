#include<bits/stdc++.h>
using namespace std;
map<long long,long long>m;
const long long N=200010;
const long long moder=1000000007;
long long n,l[N],r[N],k,fac[N],inv[N];
long long power(long long num,long long index)
{
	long long i,j,bi[40],ans=1;
	i=0;
	while (index)
	{
		bi[i++]=index%2;
		index/=2;
	}
	for (j=0;j<i;j++)
	{
		if (bi[j])
			ans=ans*num%moder;
		num=num*num%moder;
	}
	return ans;
}
int main()
{
	long long i,k,count=0,ans=0,pre;
	scanf("%I64d%I64d",&n,&k);
	for (i=0;i<n;i++)
	{
		scanf("%I64d%I64d",&l[i],&r[i]);
		if (m.count(l[i]))
			m[l[i]]++;
		else
			m[l[i]]=1;
		if (m.count(r[i]+1))
			m[r[i]+1]--;
		else
			m[r[i]+1]=-1;
	}
	fac[0]=1;
	for (i=1;i<=N;i++)
		fac[i]=fac[i-1]*i%moder;
	for (i=0;i<=N;i++)
		inv[i]=power(fac[i],moder-2);
	map<long long,long long>::iterator j=m.begin();
	for (;j!=m.end();j++)
	{
		if (j==m.begin())
			count+=j->second;
		else
		{
			if (count>=k)
				ans=(ans+(j->first-pre)*fac[count]%moder*inv[count-k]%moder*inv[k]%moder)%moder;
			count+=j->second;
		}
		pre=j->first;
	}
	printf("%I64d",ans);
	return 0;
}